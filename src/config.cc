#include "config.h"

namespace xuan_web
{

std::ostream& operator<<(std::ostream& out, const ConfigVarBase& cvb)
{
    out << cvb.getName() << ": " << cvb.toString();
    return out;
}
}
