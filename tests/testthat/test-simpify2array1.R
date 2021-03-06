expect_is(simplify2array1(list(c(1,2),c(1,2))),"matrix")
expect_error(simplify2array1(list(c("1",2))))
expect_error(simplify2array1(list(c(1,2),c(1))))
expect_error(simplify2array1(list(c(1,2,3),c(1,2,3),c(1,2))))
expect_error(simplify2array1(c(1,2),c(1,1)))
expect_equivalent(simplify2array1(list(c(1,2),c(1,2))),matrix(c(1,2,1,2),nrow=2))
expect_equivalent(simplify2array1(list(1,2,3)),matrix(c(1,2,3),nrow=1))
expect_equivalent(simplify2array1(list(c(1,2,3),c(1,2,3),c(1,2,2))),matrix(c(1,2,3,1,2,3,1,2,2),nrow=3))
expect_equivalent(simplify2array1(list(2)),matrix(c(2),nrow=1))
expect_equal(simplify2array1(list(matrix(c(1,2,3,4),nrow=2),matrix(c(1,2,3,4),nrow=2))),matrix(c(1:4,1:4),nrow=4))


