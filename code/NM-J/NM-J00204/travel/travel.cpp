#include<iostream>
using namespace std;
char A1[5]={'A','B','C'},A2[5]={'D','F'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;bool b1=1,b2=0,b3=0;
    int num[5],num_1[5];
    cin>>a>>b>>c>>d;
    if(a==c)    cout<<1;
    else cout<<0; 
    int w=0;
    for(int x:b)  
    {
       num[w]=x;
        w++;
    }
    w=0;
    for(int x:d)  
    {
        num_1[w]=x;
        w++;
    }
    for(int i=0;i<=1;i++)   
    {
        if(num[i]!=num_1[i])    b1=0;
        
    }
    if(b1==1)
    {
        for(int i=0;i<=2;i++)   
        {
            if(num[2]==int(A1[i]))
            {
                for(int j=0;j<=2;j++)
                {
                    if(num_1[2]==int(A1[j])) 
                    {
                        b2=true;
                        if(num_1[2]-1==num[2]||num_1[2]+1==num[2])  b3=1;
                    }
                }
            }
            if(num[2]==int(A2[i]))
            {
                for(int j=0;j<=2;j++)
                {
                    if(num_1[2]==int(A2[j])) 
                    {
                        b2=true;
                        if(num_1[2]-1==num[2]||num_1[2]+1==num[2])  b3=1;
                    }
                }
            }
        }
    }
    if(b1==1)   cout<<1;else cout<<0;
    if(b2==1)  cout<<1;else cout<<0;
    if(b3==1)   cout<<1;else   cout<<0;
    return 0;
}   