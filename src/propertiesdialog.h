/*
 * Tiled Map Editor (Qt)
 * Copyright 2008 Tiled (Qt) developers (see AUTHORS file)
 *
 * This file is part of Tiled (Qt).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QDialog>
#include <QMap>
#include <QString>

class QUndoStack;

namespace Ui {
class PropertiesDialog;
}

namespace Tiled {
namespace Internal {

class PropertiesModel;

class PropertiesDialog : public QDialog
{
public:
    /**
     * Constructor.
     */
    PropertiesDialog(QUndoStack *undoStack, QWidget *parent = 0);

    /**
     * Sets the properties edited by this dialog.
     */
    void setProperties(QMap<QString, QString> *properties);

    /**
     * Applies the edited properties. It does this by constructing a
     * ChangeProperties command and adding it to the undo stack.
     */
    void accept();

private:
    Ui::PropertiesDialog *mUi;
    PropertiesModel *mModel;
    QUndoStack *mUndoStack;
    QMap<QString, QString> *mProperties;
};

} // namespace Internal
} // namespace Tiled

#endif // PROPERTIESDIALOG_H