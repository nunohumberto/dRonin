/**
 ******************************************************************************
 *
 * @file       boardmanager.h
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2013
 *             Parts by Nokia Corporation (qt-info@nokia.com) Copyright (C) 2009.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup CorePlugin Core Plugin
 * @{
 * @brief The Core GCS plugin
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include <QObject>

#include "core_global.h"
#include <coreplugin/iboardtype.h>

namespace Core {

class CORE_EXPORT BoardManager : public QObject
{
    Q_OBJECT

public:
    BoardManager();
    virtual ~BoardManager();

    void init();

    /**
     * Get all board types known by the board manager as a list
     */
    QList<IBoardType *> getAvailableBoardTypes() { return m_boardTypesList; }

    /**
     * @brief getKnownVendorIDs
     * Get all USB VendorIDs known by the board manager. This can be used
     * by any plugin which uses USB and needs to know what boards are ours.
     * The list is deduplicated.
     * \deprecated use getKnownFirmwareUSBInfo or getKnownBootloaderUSBInfo instead (shouldn't be
     * filtering based on VID alone anyway since we don't own a VID
     */
    QList<int> getKnownVendorIDs();

    /**
     * @brief getKnownFirmwareUSBInfo
     * @return list of all USB information for the boards that are supported.
     * compared to "getKnownVendorIDs", this method returns more detailed info
     * allowing plugins to detect boards in a more fine-grained manner.
     */
    QList<IBoardType::USBInfo> getKnownFirmwareUSBInfo();

    /**
     * @brief getKnownBootloaderUSBInfo
     * @return list of all USB information for the boards that are supported.
     * compared to "getKnownVendorIDs", this method returns more detailed info
     * allowing plugins to detect boards in a more fine-grained manner.
     */
    QList<IBoardType::USBInfo> getKnownBootloaderUSBInfo();

    /**
     * @brief Find a board from it's type
     * @return IBoardType* on success, nullptr on failure
     */
    IBoardType *getBoard(int type);

protected:
signals:

public slots:

private slots:
    // Two slots used to detect arrival/removal of board types
    // by plugins
    void objectAdded(QObject *obj);
    void aboutToRemoveObject(QObject *obj);

protected:
    QList<IBoardType *> m_boardTypesList;

private:
};

} // namespace Core
#endif // BOARDMANAGER_H

/**
 * @}
 * @}
 */
