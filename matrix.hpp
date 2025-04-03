#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <string>

// modify this class declaration to take a template for the type of the data it holds

template <typename T>
class Matrix {
public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<T>> nums);

    static std::vector<Matrix> read_from_file(const std::string &filename);

    Matrix<T> operator+(const Matrix<T> &rhs) const;
    Matrix<T> operator*(const Matrix<T> &rhs) const;
    void set_value(std::size_t i, std::size_t j, T n);
    T get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int get_size() const{
        return _N;
    }

    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);

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
