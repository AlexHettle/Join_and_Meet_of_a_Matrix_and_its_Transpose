#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
using matrix = std::vector<std::vector<int>>;
//creates a randomly generated 5*5 boolean matrix
//(matrix that only uses 0's and 1's)
matrix Matrix_creator(){
    matrix v(5, std::vector<int>(5,0));
    for(auto &line:v){
        for(int &i:line){
            i=rand()%2;
        }
    }
    return v;
}
//Prints two matrices next to each other
void print_2_matrices(matrix m1,matrix m2){
    for(int i=0;i<5;i++){
        std::cout<<"\t";
        for(int j=0;j<5;j++){
            std::cout<<m1[i][j]<<" ";
        }
        std::cout<<"\t";
        for(int k=0;k<5;k++){
            std::cout<<m2[i][k]<<" ";
        }
        std::cout<<"\n";
    }
}
//Goes through each position of one matrix
//and compares it to same position of
//the other to find the OR of that position
matrix join(matrix m1,matrix m2){
    matrix mjoin(5, std::vector<int>(5,0));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(m1[i][j]||m2[i][j]){
                mjoin[i][j]=1;
            }
        }
    }
    return mjoin;
}
//Goes through each position of one matrix
//and compares it to same position of
//the other to find the AND of that position
matrix meet(matrix m1,matrix m2){
    matrix mmeet(5, std::vector<int>(5,0));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(m1[i][j]&&m2[i][j]){
                mmeet[i][j]=1;
            }
        }
    }
    return mmeet;
}
//Finds the transpose of a matrix
matrix transpose(matrix m){
    matrix transposed_matrix(5, std::vector<int>(5,0));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            transposed_matrix[i][j]=m[j][i];
        }
    }
    return transposed_matrix;
}
//goes through the process of creating a matrix,
//findings its transpose, and then finding the AND and
//OR of the two matrices
void process(){
    std::string choice;
    matrix m1=Matrix_creator();
    matrix m2=transpose(m1);
    std::cout<<"The initial randomly generated 5X5 zero-one matrix and its transpose:\n";
    std::cout<<"     Original matrix  transposed matrix\n";
    print_2_matrices(m1,m2);
    std::cout<<"The join and meet of the two matrices:\n";
    std::cout<<"\t  join\t\t  meet\n";
    print_2_matrices(join(m1,m2),meet(m1,m2));
    std::cout<<"enter 1 if you want this program to run again:\n";
    std::cin>>choice;
    if(choice=="1"){
        process();
    }
}
int main(){
    srand(time(NULL));
    process();
}

