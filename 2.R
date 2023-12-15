numeric <- subset(combined_OUT, PasswordType == 'Numbers Only')
lowercase <- subset(combined_OUT, PasswordType == 'Lowercase Only')
mixed <- subset(combined_OUT, PasswordType == 'Mixed Characters')

combinedData <- rbind(numeric, lowercase, mixed)
library(ggplot2)

ggplot(combinedData, aes(x = PasswordType, y = Time)) +
  geom_boxplot() +
  scale_y_log10() +
  labs(title = "Password Cracking Time by Complexity",
       x = "Password Complexity",
       y = "Time to Crack (seconds)") +
  theme_minimal()

ciNumeric <- t.test(numeric$Time, conf.level = 0.95)$conf.int
ciLowercase <- t.test(lowercase$Time, conf.level = 0.95)$conf.int
ciMixed <- t.test(mixed$Time, conf.level = 0.95)$conf.int

ciNumeric
ciLowercase
ciMixed