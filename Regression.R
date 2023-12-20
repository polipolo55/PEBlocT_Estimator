head(Combe2)

Combe2$PasswordType <- as.factor(Combe2$PasswordType)

model <- lm(Time ~ passwordLength + PasswordType, data = Combe2)
summary(model)

modelLog <- lm(log(Time) ~ passwordLength + PasswordType, data = Combe2)
summary(modelLog)

plot(model)
plot(modelLog)