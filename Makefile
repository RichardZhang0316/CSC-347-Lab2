all: MatrixMult.cu
	nvcc -o MatrixMult MatrixMult.cu
clean:
	rm -f MatrixMult