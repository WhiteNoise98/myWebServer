#ifndef SERVER_FARMEWORK_NONCOPYABLE_H
#define SERVER_FARMEWORK_NONCOPYABLE_H

namespace xuan_web
{

/**
*
* @brief 禁用拷贝构造操作
* 继承使用
*/
class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};
} // namespace xuan_web

#endif
