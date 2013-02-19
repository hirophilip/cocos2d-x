/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CCKeyboard_DELEGATE_H__
#define __CCKeyboard_DELEGATE_H__


#include "cocoa/CCObject.h"

NS_CC_BEGIN

/**
 * @addtogroup input
 * @{
 */

class CC_DLL CCKeyboardDelegate
{
public:
    // A key was pressed Down
    virtual void ccKeyDown(unsigned short keyCode) {}

    // A key was released Up
    virtual void ccKeyUp(unsigned short keyCode) {};
    
    // A system key state was changed
    virtual void ccKeyFlagsChanged(int maskCode) {};
};

/**
@brief
CCKeyboardHandler
Object than contains the CCKeyboardDelegate.
*/
class CC_DLL CCKeyboardHandler : public CCObject
{
public:
    virtual ~CCKeyboardHandler(void);

    /** delegate */
    CCKeyboardDelegate* getDelegate();
    void setDelegate(CCKeyboardDelegate *pDelegate);

    /** initializes a CCKeyboardHandler with a delegate */
    virtual bool initWithDelegate(CCKeyboardDelegate *pDelegate);

public:
    /** allocates a CCKeyboardHandler with a delegate */
    static CCKeyboardHandler* handlerWithDelegate(CCKeyboardDelegate *pDelegate);

protected:
    CCKeyboardDelegate* m_pDelegate;
};

// end of input group
/// @} 

NS_CC_END

#endif // __CCKeyboard_DELEGATE_H__
