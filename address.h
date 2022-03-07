#ifndef XUAN_WEB_ADDRESS_H
#define XUAN_WEB_ADDRESS_H

#include <memory>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>

namespace xuan_web
{

/**
 * @brief 地址基类
*/
class Address
{
public:
    using ptr = std::shared_ptr<Address>;

    virtual ~Address() = default;

    // 获取协议族
    int getFamily() const;

    // @brief 获取 socket 地址
    virtual const sockaddr* getAddr() const = 0;

    // @brief 获取地址长度
    virtual socklen_t getAddrLen() const = 0;

    std::string toString();

    bool operator<(const Address& rhs) const;

    bool operator==(const Address& rhs) const;

    bool operator!=(const Address& rhs) const;

protected:
    virtual std::ostream& insert(std::ostream& os) const;
};

/**
 * @brief IP 地址基类
*/
class IPAddress : public Address
{
public:
    using ptr = std::shared_ptr<IPAddress>;

    // 获取广播地址
    virtual IPAddress::ptr broadcastAddress(uint32_t prefix_len) = 0;

    // 获取网络地址
    virtual IPAddress::ptr networkAddress(uint32_t prefix_len) = 0;

    // 获取子网掩码
    virtual IPAddress::ptr subnetMask(uint32_t prefix_len) = 0;

    // 获取端口号
    virtual uint32_t getPort() const = 0;

    virtual void setPort(uint16_t port) = 0;
};

/**
 * @brief IPv4 地址信息类
*/
class IPv4Address : public IPAddress
{
public:
    using ptr = std::shared_ptr<IPv4Address>;

    IPv4Address(uint32_t address = INADDR_ANY, uint16_t port = 0);

    // 获取 socket 地址
    const sockaddr* getAddr() const override;

    // 获取地址长度
    socklen_t getAddrLen() const override;

    // 获取广播地址
    IPAddress::ptr broadcastAddress(uint32_t prefix_len) override;

    // 获取网络地址
    IPAddress::ptr networkAddress(uint32_t prefix_len) override;

    // 获取子网掩码
    IPAddress::ptr subnetMask(uint32_t prefix_len) override;

    // 获取端口号
    uint32_t getPort() const override;

    void setPort(uint16_t port) override;

protected:
    std::ostream& insert(std::ostream& os) const override;

private:
    sockaddr_in m_addr;
};

/**
 * @brief IPv6 地址信息类
*/
class IPv6Address : public IPAddress
{
public:
    using ptr = std::shared_ptr<IPv6Address>;

    IPv6Address();

    IPv6Address(const char *address = "", uint16_t port = 0);

    // 获取 socket 地址
    const sockaddr* getAddr() const override;

    // 获取地址长度
    socklen_t getAddrLen() const override;

    // 获取广播地址
    IPAddress::ptr broadcastAddress(uint32_t prefix_len) override;

    // 获取网络地址
    IPAddress::ptr networkAddress(uint32_t prefix_len) override;

    // 获取子网掩码
    IPAddress::ptr subnetMask(uint32_t prefix_len) override;

    // 获取端口号
    uint32_t getPort() const override;

    void setPort(uint16_t port) override;

protected:
    std::ostream& insert(std::ostream& os) const override;

private:
    sockaddr_in6 m_addr;
};

/**
 * @brief Unix 地址信息类
*/
class UnixAddress : public Address
{
public:
    using ptr = std::shared_ptr<UnixAddress>;

    UnixAddress(const std::string& path);

    // 获取 socket 地址
    const sockaddr* getAddr() const override;

    // 获取地址长度
    socklen_t getAddrLen() const override;

protected:
    std::ostream& insert(std::ostream& os) const override;

private:
    sockaddr_in m_addr;
    socklen_t m_length;
};

/**
 * @brief 未知地址信息类
*/
class UnknowAddress : public Address
{
public:
    using ptr = std::shared_ptr<UnknowAddress>;

    UnknowAddress();

    // 获取 socket 地址
    const sockaddr* getAddr() const override;

    // 获取地址长度
    socklen_t getAddrLen() const override;

protected:
    std::ostream& insert(std::ostream& os) const override;

private:
    sockaddr m_addr;
    socklen_t m_length;
};

} // namespace xuan_web

#endif
