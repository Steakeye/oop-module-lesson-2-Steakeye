#pragma once

//This is for part 1
class ILogger {
public:
    virtual ILogger& LogInfo(const std::string& msg) = 0;
    virtual ILogger& LogError(const std::string& msg) = 0;
    virtual const std::string& GetLastError() const  = 0;
    virtual ~ILogger() = default;
};

// This is for Part 2/3
class StringLogger: public ILogger {
    std::ostream& stream;
    std::string lastError;

public:
    StringLogger(std::ostream& initStream): stream(initStream) {}

    ILogger& LogInfo(const std::string& message) override {
        stream << "INFO: " + message;

        return *this;
    }

    ILogger& LogError(const std::string& message) {
        lastError = message;

        stream << "ERROR: " + message;

        return *this;
    }

    const std::string& GetLastError() const {
        return lastError;
    }
};

