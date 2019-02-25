#pragma once
#include "EXERCISE.h"

// This is for Part 2/3
StringLogger::StringLogger(std::ostream &initStream): stream(initStream)  {}

ILogger& StringLogger::LogInfo(const std::string& message) {
    stream << "INFO: " + message;

    return *this;
}

ILogger& StringLogger::LogError(const std::string& message) {
    lastError = message;

    stream << "ERROR: " + message;

    return *this;
}

const std::string& StringLogger::GetLastError() const {
    return lastError;
}

int StringLogger::version = 2;

int StringLogger::Version() {
    return version;
}