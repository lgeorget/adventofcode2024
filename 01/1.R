library(data.table)


a <- fread('./input')
names(a) <- c('left','right')

# first part
sum(abs(sort(a$left) - sort(a$right)))

# second part
b <- a[, .(count=sum(left==a$right)), by=left]
sum(a$left*b$count)

