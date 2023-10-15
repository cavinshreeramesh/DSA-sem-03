#include <iostream>
using namespace std;

int main()
{
    int **matrix_a,**matrix_b,**matrix_result;
    int a_row,a_col,b_row,b_col,i,j,k;
    cout<<"enter no. of rows of matrix a: ";
    cin>>a_row;
    cout<<"enter no. of columns of matrix a: ";
    cin>>a_col;
    cout<<"enter no. of rows of matrix b: ";
    cin>>b_row;
    cout<<"enter no. of columns of matrix b: ";
    cin>>b_col;
    if(a_col!=b_row){
        cout<<"Invalid matrix sizes";
    }else{
        matrix_a=(int**)malloc(a_row*sizeof(int*));
        matrix_b=(int**)malloc(b_row*sizeof(int*));
        matrix_result=(int**)malloc(a_row*sizeof(int*));
        
        for(i=0;i<a_row;i++){
            matrix_a[i]=(int*)malloc(a_col*sizeof(int));
            matrix_result[i]=(int*)malloc(a_col*sizeof(int));
        }
        for(i=0;i<b_row;i++){
            matrix_b[i]=(int*)malloc(b_col*sizeof(int));
        }
        
        cout<<"enter matrix a: "<<endl;
        for(i=0;i<a_row;i++){
            for(j=0;j<a_col;j++){
                cout<<" row "<<i+1<<" col "<<j+1<<": ";
                cin>>matrix_a[i][j];
            }
        }
        cout<<"enter matrix b: "<<endl;
        for(i=0;i<b_row;i++){
            for(j=0;j<b_col;j++){
                cout<<" row "<<i+1<<" col "<<j+1<<": ";
                cin>>matrix_b[i][j];
            }
        }
        
        for(i=0;i<a_row;i++){
            for(j=0;j<b_col;j++){
                matrix_result[i][j]=0;
                for(k=0;k<a_col;k++){
                    matrix_result[i][j]+=matrix_a[i][k]*matrix_b[k][j];
                }
            }
        }
        
        cout<<"The resultant matrix: "<<endl;
        for(i=0;i<b_row;i++){
            cout<<" ";
            for(j=0;j<b_col;j++){
                cout<<matrix_result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}