library(data.table)

isSafe <- function (a) {
	b <- a - c(a[2:length(a)],a[length(a)])
	if (!all(b<=0) && !all(b>=0))
		return(FALSE)
	sub <- abs(b[1:length(b)-1])
	return(all(sub >= 1 & sub <= 3))
}

# first part
f <- file("./input", "r")
safe <- 0
while (T) {
	line <- readLines(f, n=1)
	if (length(line) == 0)
		break

	a <- as.numeric(unlist(strsplit(line, " ")))
	safe <- safe + isSafe(line)
}
close(f)
print(safe)


# second part
f <- file("./input", "r")
safe <- 0
while (T) {
	line <- readLines(f, n=1)
	if (length(line) == 0)
		break

	a <- as.numeric(unlist(strsplit(line, " ")))
	safe <- safe + any(sapply(1:length(a), function (i) { isSafe(a[-i]) }))
}
close(f)
print(safe)
