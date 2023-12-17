Combe2$passwordLength <- nchar(Combe2$Password)

numericData <- subset(Combe2, PasswordType == 'Numbers Only')
mixedData <- subset(Combe2, PasswordType == 'Mixed Characters')

numericMean <- aggregate(Time ~ passwordLength, data = numericData, mean)
mixedMean <- aggregate(Time ~ passwordLength, data = mixedData, mean)


useful <- rbind(numericData, mixedData)

library(ggplot2)

numericMean$passwordType <- 'Numeric Only'
mixedMean$passwordType <- 'Mixed Characters'

numericData$passwordType <- 'Numeric Only'
mixedData$passwordType <- 'Mixed Characters'

ggplot(useful, aes(x = passwordLength, y = Time)) +
  geom_point(alpha = 0.5) +
  scale_y_log10() +
  labs(title = "Cracking Time vs. Password Length for Numeric Only Passwords",
       x = "Password Length (Number of Characters)",
       y = "Time to Crack (seconds)") +
  theme_minimal()

useful <- rbind(numericData, mixedData)

combinedMean <- rbind(numericMean, mixedMean)
combinedData <- rbind(numericMean, mixedMean)

ggplot(useful, aes(x = passwordLength, y = Time, color = passwordType)) +
  geom_point(alpha = 0.5) +
  scale_y_log10() +
  labs(title = "Mean Cracking Time vs. Password Length",
       x = "Password Length (Number of Characters)",
       y = "Mean Time to Crack (seconds, log scale)") +
  theme_minimal()

numericData2 <- subset(combined_OUT, PasswordType == 'Numbers Only')
mixedData2 <- subset(combined_OUT, PasswordType == 'Mixed Characters')

longSimple <- subset(numericData2, nchar(Password) >= 5 & nchar(Password) <= 13)
shortComplex <- subset(mixedData2, nchar(Password) >= 3 & nchar(Password) <= 5)

tTestResult <- t.test(longSimple$Time, shortComplex$Time)

tTestResult

ml <- mean(longSimple$Time)
ms <- mean(shortComplex$Time)

ml
ms

numericData$logTimeToCrack <- log(numericData$Time)
mixedData$logTimeToCrack <- log(mixedData$Time)



qqnorm(numericData$logTimeToCrack)
qqline(numericData$logTimeToCrack, col = "red")

qqnorm(mixedData$logTimeToCrack)
qqline(mixedData$logTimeToCrack, col = "red")

ciNumeric <- t.test(numericData$logTimeToCrack, conf.level = 0.95)$conf.int
ciMixed <- t.test(mixedData$logTimeToCrack, conf.level = 0.95)$conf.int

ciNumeric
ciMixed


