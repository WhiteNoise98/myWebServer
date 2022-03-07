#include "exception.h"
#include "util.h"
#include <utility>

namespace xuan_web
{
/**
 * =======================================
 * Exception 的实现
 * =======================================
*/

Exception::Exception(std::string what)
    : m_message(std::move(what)),
      m_stack(BacktraceToString(200))
{
}

const char* Exception::what() const noexcept
{
    return m_message.c_str();
}

const char* Exception::stackTrace() const noexcept
{
    return m_stack.c_str();
}

/**
 * =======================================
 * SystemError 的实现
 * =======================================
*/

SystemError::SystemError(std::string what)
    : Exception(what + " : " + std::string(::strerror(errno)))
{
}

} // namespace xuan_web
