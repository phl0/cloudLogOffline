//=============================================================================
// Copyright (c) 2014 Nicolas Froment

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//=============================================================================

#include "shareutils.h"

#ifdef Q_OS_IOS
#include "ios/iosshareutils.h"
#endif

#ifdef Q_OS_ANDROID
#include "android/androidshareutils.h"
#endif

shareUtils::shareUtils(QQuickItem *parent) : QQuickItem(parent)
{
#if defined(Q_OS_IOS)
    _pShareUtils = new iosShareUtils(this);
#elif defined(Q_OS_ANDROID)
    _pShareUtils = new AndroidShareUtils(this);
#else
    _pShareUtils = new platformShareUtils(this);
#endif
}

void shareUtils::share(const QString &text)
{
    _pShareUtils->share(text);
}

void shareUtils::shareADIF()
{
    share(adif.generate());
}

void shareUtils::shareCabrillo(
        QString cabrilloContest,
        QString cabrilloAssisted,
        QString cabrilloBand,
        QString cabrilloMode,
        QString cabrilloOperator,
        QString cabrilloPower,
        QString cabrilloStation,
        QString cabrilloTime,
        QString cabrilloTransmitter,
        QString cabrilloOverlay,
        QString cabrilloCertificate,
        QString cabrilloScore,
        QString cabrilloClub,
        QString cabrilloEmail,
        QString cabrilloGridLocator,
        QString cabrilloLocation,
        QString cabrilloName,
        QString cabrilloAddress,
        QString cabrilloOperators,
        QString cabrilloSoapbox
    )
{
    share(cabrillo.generate(
              cabrilloContest,
              cabrilloAssisted,
              cabrilloBand,
              cabrilloMode,
              cabrilloOperator,
              cabrilloPower,
              cabrilloStation,
              cabrilloTime,
              cabrilloTransmitter,
              cabrilloOverlay,
              cabrilloCertificate,
              cabrilloScore,
              cabrilloClub,
              cabrilloEmail,
              cabrilloGridLocator,
              cabrilloLocation,
              cabrilloName,
              cabrilloAddress,
              cabrilloOperators,
              cabrilloSoapbox
              ));
}

void shareUtils::shareCSV()
{
    share(csv.generate());
}
