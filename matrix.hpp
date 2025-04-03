#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <string>

// modify this class declaration to take a template for the type of the data it holds

template <typename T>
class Matrix {
public:

    Matrix(std::size_t N) : _N(N), nums(N, std::vector<T>(N, 0)) {}

    Matrix(std::vector<std::vector<T>> nums) : _N(nums.size()), nums(std::move(nums)) {}

    static std::vector<Matrix<T>> read_from_file(const std::string &filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }
        
        std::size_t N;
        file >> N;
        
        std::vector<std::vector<T>> matrix1(N, std::vector<T>(N));
        std::vector<std::vector<T>> matrix2(N, std::vector<T>(N));
        
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                file >> matrix1[i][j];
            }
        }
        
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j) {
                file >> matrix2[i][j];
            }
        }
        
        return {Matrix(matrix1), Matrix(matrix2)};
    }

    Matrix<T> operator+(const Matrix &rhs) const {
        if (_N != rhs._N) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }
        Matrix result(_N);
        for (std::size_t i = 0; i < _N; ++i) {
            for (std::size_t j = 0; j < _N; ++j) {
                result.nums[i][j] = nums[i][j] + rhs.nums[i][j];
            }
        }
        return result;
    }
    
    Matrix<T> operator*(const Matrix &rhs) const {
        if (_N != rhs._N) {
            throw std::invalid_argument("Matrix dimensions must match for multiplication");
        }
        Matrix result(_N);
        for (std::size_t i = 0; i < _N; ++i) {
            for (std::size_t j = 0; j < _N; ++j) {
                for (std::size_t k = 0; k < _N; ++k) {
                    result.nums[i][j] += nums[i][k] * rhs.nums[k][j];
                }
            }
        }
        return result;
    }

    void set_value(std::size_t i, std::size_t j, T n) {
        if (i >= _N || j >= _N) {
            throw std::out_of_range("Index out of range");
        }
        nums[i][j] = n;
    }

    T get_value(std::size_t i, std::size_t j) const {
        if (i >= _N || j >= _N) {
            throw std::out_of_range("Index out of range");
        }
        return nums[i][j];
    }

    int get_size() const{
        return _N;
    }

    T sum_diagonal_major() const{
        T sum = 0;
        for (std::size_t i = 0; i < _N; ++i) {
            sum += nums[i][i];
        }
        return sum;
    }
    
    T sum_diagonal_minor() const{
        T sum = 0;
        for (std::size_t i = 0; i < _N; ++i) {
            sum += nums[i][_N - i - 1];
        }
        return sum;
    }

    void swap_rows(std::size_t r1, std::size_t r2){
        if (r1 >= _N || r2 >= _N) {
            throw std::out_of_range("Row index out of range");
        }
        std::swap(nums[r1], nums[r2]);
    }

    void swap_cols(std::size_t c1, std::size_t c2){
        if (c1 >= _N || c2 >= _N) {
            throw std::out_of_range("Column index out of range");
        }
        for (std::size_t i = 0; i < _N; ++i) {
            std::swap(nums[i][c1], nums[i][c2]);
        }
    }

    void print_matrix() const{
        for (const auto &row : nums) {
            for (const auto &elem : row) {
                std::cout << std::setw(5) << elem << " ";
            }
            std::cout << '\n';
        }
        
    }

private:
    std::size_t _N;
    std::vector<std::vector<T>> nums;

};

#endif // __MATRIX_HPP__
