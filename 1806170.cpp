#include <iostream>

using namespace std;

void Begin(){
    cout<<"\t\t\t\t\t*********************\n";

    cout<<"\t\t\t\t\t**Matrix Calculator** \n";
    cout<<"\t\t\t\t\t*********************\n";
   
}

int main()
{ int Size,out=0, out2 =0 ,out3=0 ,rows,col,sum=0 ,amount,op1,D,I,op2;
double det=0;
  char Q;

  Begin();

   do   // do-while loop for the whole program will exit only when user enters Q
    {
    cout<<"\n Choose number of matrix/es you want to enter either 1 or 2\n"<<"\tfor 1 matrix Enter 1\t" <<" \tfor 2 matrices enter 2\n"<<"\tEnter Q for Exit"<<endl;
    cin>>amount;   //input the number of wanted matrices
if (amount == 1)  //Check the input and executes this block if user chooses to enter 1 matrix
{

        cout<<"Choose the Size of your matrix either 2*2 or 3*3\n"<<"Enter 2 for 2*2\n" << "Enter 3 for 3*3\n"<<"Enter Q for exit "<<endl;
        cin>>Size;                   // input the size of matrix
        if (Size == 2 || Size == 3) //check if Size is entered from the given options
        {
            double mat1 [Size][Size];
                for(rows=0 ; rows<Size ; rows++)
                    for(col=0 ; col<Size ; col++)
                    {
                        cout<<"Enter item in row:"<<rows+1<<"\t and in column:"<<col+1<<"\n"<<endl;
                        cin>> mat1 [rows][col];
                    }
                    cout<<"Matrix is:  \n" ;
                for(rows=0 ; rows<Size ; rows++){
                    for(col=0 ; col<Size ; col++){
                        cout<<"\t"<<mat1[rows][col];}
                        cout<<endl;

                }
                cout<<"Size of your matrix is "<<Size<<"*"<< Size<<"\n"<<endl;

               do{ // do-while loop for the operations available for 1 matrix and will exit only if user entered 6

                    cout<< "\n\n To get the Determinant of matrix Enter 8 \t\t To get the Inverse of matrix Enter 9 \n Enter 6 to enter new matrix"<<endl;
                cin>>op1;
                if(op1 == 8){

                       if(Size == 2){

                        cout<<"\n \n Determinant of this matrix is "<< ((mat1[0][0] * mat1[1][1]) - (mat1[1][0] * mat1[0][1])) <<endl;}
                        else if(Size == 3) {det=(((mat1[0][0])*(mat1[1][1]*mat1[2][2]-mat1[1][2]*mat1[2][1]))-((mat1[0][1])*(mat1[1][0]*mat1[2][2]-mat1[1][2]*mat1[2][0]))+((mat1[0][2])*(mat1[1][0]*mat1[2][1]-mat1[1][1]*mat1[2][0])));
                        cout<<"\n\n Determinant of this matrix is "<<det<<"\n\n"<<endl;}}


                else if(op1 == 9){
                    if(Size == 3){
                        det=(((mat1[0][0])*(mat1[1][1]*mat1[2][2]-mat1[1][2]*mat1[2][1]))-((mat1[0][1])*(mat1[1][0]*mat1[2][2]-mat1[1][2]*mat1[2][0]))+((mat1[0][2])*(mat1[1][0]*mat1[2][1]-mat1[1][1]*mat1[2][0])));
                        if(det != 0){
                        double cof1[Size][Size];
                        cof1[0][0]=mat1[1][1]*mat1[2][2]-mat1[1][2]*mat1[2][1];
                        cof1[0][1]=-(mat1[1][0]*mat1[2][2]-mat1[1][2]*mat1[2][0]);
                        cof1[0][2]=mat1[1][0]*mat1[2][1]-mat1[1][1]*mat1[2][0];
                        cof1[1][0]=-(mat1[0][1]*mat1[2][2]-mat1[0][2]*mat1[2][1]);
                        cof1[1][1]=mat1[0][0]*mat1[2][2]-mat1[0][2]*mat1[2][0];
                        cof1[1][2]=-(mat1[0][0]*mat1[2][1]-mat1[0][1]*mat1[2][0]);
                        cof1[2][0]=mat1[0][1]*mat1[1][2]-mat1[0][2]*mat1[1][1];
                        cof1[2][1]=-(mat1[0][0]*mat1[1][2]-mat1[0][2]*mat1[1][0]);
                        cof1[2][2]=mat1[0][0]*mat1[1][1]-mat1[0][1]*mat1[1][0];

                        double adj1[Size][Size];

                        adj1[0][0]=mat1[1][1]*mat1[2][2]-mat1[1][2]*mat1[2][1];
                        adj1[0][1]=-(mat1[0][1]*mat1[2][2]-mat1[0][2]*mat1[2][1]);
                        adj1[0][2]=mat1[0][1]*mat1[1][2]-mat1[0][2]*mat1[1][1];

                        adj1[1][0]=-(mat1[1][0]*mat1[2][2]-mat1[1][2]*mat1[2][0]);
                        adj1[1][1]=mat1[0][0]*mat1[2][2]-mat1[0][2]*mat1[2][0];
                        adj1[1][2]=-(mat1[0][0]*mat1[1][2]-mat1[0][2]*mat1[1][0]);

                        adj1[2][0]=mat1[1][0]*mat1[2][1]-mat1[1][1]*mat1[2][0];
                        adj1[2][1]=-(mat1[0][0]*mat1[2][1]-mat1[0][1]*mat1[2][0]);
                        adj1[2][2]=mat1[0][0]*mat1[1][1]-mat1[0][1]*mat1[1][0];

                        cout<<"\n Adjoint Matrix is:  \n" ;
                for(rows=0 ; rows<Size ; rows++){
                    for(col=0 ; col<Size ; col++){
                        cout<<"\t"<<adj1[rows][col];}
                        cout<<endl;}

                        double inv1[Size][Size];

                        inv1[0][0]=(mat1[1][1]*mat1[2][2]-mat1[1][2]*mat1[2][1])*(1/det);
                        inv1[0][1]=(-(mat1[0][1]*mat1[2][2]-mat1[0][2]*mat1[2][1]))*(1/det);
                        inv1[0][2]=(mat1[0][1]*mat1[1][2]-mat1[0][2]*mat1[1][1])*(1/det);

                        inv1[1][0]=(-(mat1[1][0]*mat1[2][2]-mat1[1][2]*mat1[2][0]))*(1/det);
                        inv1[1][1]=(mat1[0][0]*mat1[2][2]-mat1[0][2]*mat1[2][0])*(1/det);
                        inv1[1][2]=(-(mat1[0][0]*mat1[1][2]-mat1[0][2]*mat1[1][0]))*(1/det);

                        inv1[2][0]=(mat1[1][0]*mat1[2][1]-mat1[1][1]*mat1[2][0])*(1/det);
                        inv1[2][1]=(-(mat1[0][0]*mat1[2][1]-mat1[0][1]*mat1[2][0]))*(1/det);
                        inv1[2][2]=(mat1[0][0]*mat1[1][1]-mat1[0][1]*mat1[1][0])*(1/det);





                    cout<<"\n\nInverse of matrix is: \n";
                     for(rows=0 ; rows<Size ; rows++){
                    for(col=0 ; col<Size ; col++){
                        cout<<"\t"<<inv1[rows][col];}
                        cout<<endl;}}

                   else if (det == 0){cout<<"can't get the inverse as the determinant is equal to zero! " <<endl;}}
                else if (Size == 2) {
                    det=((mat1[0][0] * mat1[1][1]) - (mat1[1][0] * mat1[0][1]));
                    if(det != 0){
                        double Min1[Size][Size];
                        Min1[0][0]=mat1[1][1];
                        Min1[0][1]=-(mat1[0][1]);
                        Min1[1][0]=-(mat1[1][0]);
                        Min1[1][1]=mat1[0][0];
                        double inv2[Size][Size];
                         inv2[0][0]=(mat1[1][1])*(1/det);
                        inv2[0][1]=(-(mat1[0][1]))*(1/det);
                        inv2[1][0]=(-(mat1[1][0]))*(1/det);
                        inv2[1][1]=(mat1[0][0])*(1/det);
                        cout<<"\n\nInverse of matrix is: \n";
                     for(rows=0 ; rows<Size ; rows++){
                    for(col=0 ; col<Size ; col++){
                        cout<<"\t"<<inv2[rows][col];}
                        cout<<endl;}
                    }
                       else if(det == 0){ cout<<"\n  can't get the inverse as the determinant is equal to zero!" ;}}}
                else if(op1=6){out2=1;}


               else{ cout<<"\n unkown input\n" ;}
                }while(out2 == 0);
        }

        else if(Size == Q)
            {
                out=1;
                exit;
            }

        else
            {
                cout<<"\n non-declared Choice! :) \n " << endl;
            }

}
else if (amount == 2)
{
        cout<<"Choose the Size of your two matrices either 2*2 or 3*3\n"<<"Enter 2 for 2*2\n" << "Enter 3 for 3*3\n"<<"Enter Q for exit "<<endl;
        cin>>Size;
        if (Size == 2 || Size == 3)
        {
            double mat2 [Size][Size];
            double mat3 [Size][Size];
                for(rows=0 ; rows<Size ; rows++)
                    for(col=0 ; col<Size ; col++)
                    {
                        cout<<" (For the first matrix)  Enter item in row:"<<rows+1<<"\t and in column:"<<col+1<<"\n"<<endl;
                        cin>> mat2 [rows][col];
                    }
                    for(rows=0 ; rows<Size ; rows++)
                    for(col=0 ; col<Size ; col++)
                    {
                        cout<<" (For the Second matrix)  Enter item in row:"<<rows+1<<"\t and in column:"<<col+1<<"\n"<<endl;
                        cin>> mat3 [rows][col];
                    }
                     cout<<"First Matrix is:  \n" ;
                for(rows=0 ; rows<Size ; rows++){
                    for(col=0 ; col<Size ; col++){
                        cout<<"\t"<<mat2[rows][col];}
                        cout<<endl;}
                 cout<<"\n Second Matrix is:  \n" ;
                for(rows=0 ; rows<Size ; rows++){
                    for(col=0 ; col<Size ; col++){
                        cout<<"\t"<<mat3[rows][col];}
                        cout<<endl;}

                  do{ cout<< "\n To get the Sum of the matrices Enter 8 \t\t To get the product of matrices Enter 9 \n to get difference (matrix 1 - matrix 2) Enter 5 \t\t Enter 6 to Enter new matrices"<<endl;
                cin>>op2;
                if (op2== 8){

                       if(Size == 2){
                            cout<<"\nThe sum is"<<"\n"<<"\t"<<mat2[0][0]+mat3[0][0]<<"\t"<<mat2[0][1]+mat3[0][1]<<"\n"<<"\t"<<mat2[1][0]+mat3[1][0]<<"\t"<<mat2[1][1]+mat3[1][1]<<endl;
                       }
                       else if (Size == 3){
                             cout<<"\n The sum is"<<"\n"<<"\t"<<mat2[0][0]+mat3[0][0]<<"\t"<<mat2[0][1]+mat3[0][1]<<"\t"<<mat2[0][2]+mat3[0][2]<<"\n"<<"\t"<<mat2[1][0]+mat3[1][0]<<"\t"<<mat2[1][1]+mat3[1][1]<<"\t"<<mat2[1][2]+mat3[1][2]
                             <<"\n"<<"\t"<<mat2[2][0]+mat2[2][0]<<"\t"<<mat2[2][1]+mat3[2][1]<<"\t"<<mat2[2][2]+mat3[2][2]<<endl;
                       }}

                    else if (op2 == 5){
                        if(Size == 2){
                            cout<<"\n The Difference is"<<"\n"<<"\t"<<mat2[0][0]-mat3[0][0]<<"\t"<<mat2[0][1]-mat3[0][1]<<"\n"<<"\t"<<mat2[1][0]-mat3[1][0]<<"\t"<<mat2[1][1]-mat3[1][1]<<endl;
                       }
                       else if (Size == 3){
                             cout<<"\n The Difference is"<<"\n"<<"\t"<<mat2[0][0]-mat3[0][0]<<"\t"<<mat2[0][1]-mat3[0][1]<<"\t"<<mat2[0][2]-mat3[0][2]<<"\n"<<"\t"<<mat2[1][0]-mat3[1][0]<<"\t"<<mat2[1][1]-mat3[1][1]<<"\t"<<mat2[1][2]-mat3[1][2]<<"\n"<<"\t"<<mat2[2][0]-mat2[2][0]<<"\t"<<mat2[2][1]-mat3[2][1]<<"\t"<<mat2[2][2]-mat3[2][2]<<endl;
                       }}
                    else if (op2 == 6){
                        out3=1;}
                    else if(op2 == 9){
                        if(Size == 2){
                            cout<<"\n The product is: "<<"\n"<<"\t"<<mat2[0][0]*mat3[0][0]+mat2[0][1]*mat3[1][0]<<"\t"<<mat2[0][0]*mat3[0][1]+mat2[0][1]*mat3[1][1]<<"\n"<<"\t"<<mat2[1][0]*mat3[0][0]+mat2[1][1]*mat3[1][0]<<"\t"<<mat2[1][0]*mat3[0][1]+mat2[1][1]*mat3[1][1]<<endl;
                        }
                        else if (Size == 3){
cout<<"\n The product is: "<<"\n"<<"\t"<<mat2[0][0]*mat3[0][0]+mat2[0][1]*mat3[1][0]+mat2[0][2]*mat3[2][0]<<"\t"
<<mat2[0][0]*mat3[0][1]+mat2[0][1]*mat3[1][1]+mat2[0][2]*mat3[2][1]<<"\t"<<mat2[0][0]*mat3[0][2]+mat2[0][1]*mat3[1][2]+mat2[0][2]*mat3[2][2]<<"\n"
<<"\t"<<mat2[1][0]*mat3[0][0]+mat2[1][1]*mat3[1][0]+mat2[1][2]*mat3[2][0]<<"\t"<<mat2[1][0]*mat3[0][1]+mat2[1][1]*mat3[1][1]+mat2[1][2]*mat3[2][1]<<"\t"<<mat2[1][0]*mat3[0][2]+mat2[1][1]*mat3[1][2]+mat2[1][2]*mat3[2][2]<<"\n"
<<"\t"<<mat2[2][0]*mat3[0][0]+mat2[2][1]*mat3[1][0]+mat2[2][2]*mat3[2][0]<<"\t"<<mat2[2][0]*mat3[0][1]+mat2[2][1]*mat3[1][1]+mat2[2][2]*mat3[2][1]<<"\t"<<mat2[2][0]*mat3[0][2]+mat2[2][1]*mat3[1][2]+mat2[2][2]*mat3[2][2]<<endl;

                        }}


        }while(out3 == 0);
                }
        else if(Size == Q)
            {
                out=1;
                exit;
            }

        else
            {
                cout<<"non-declared Choice! :) \n " << endl;
            }

}
else if(amount == Q){
    out =1;
}
else
{
    cout<<" Options are 1 or 2 Only :) \n Program exit..." <<endl;
    out=1;

}


    }while(out ==0);
    return 0;
}

