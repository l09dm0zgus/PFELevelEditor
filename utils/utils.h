#ifndef UTILS_H
#define UTILS_H

#define HOME_DIRECTORY getHomeDirectory()

#include <QString>
static QString getHomeDirectory()
{
#if defined(Q_OS_WIN)
    return QLatin1String("C:/Users/Public");
#elif defined(Q_OS_LINUX)
    return QLatin1String("/home");
#endif
}
#endif // UTILS_H
