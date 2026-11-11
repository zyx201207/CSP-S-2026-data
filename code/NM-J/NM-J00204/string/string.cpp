#include<iostream>
using namespace std;
int a[1000];char c[1000];
char w[10000];
int debate(int number,int num)
{
    for(int i=number-1;i>=0;i--)
    {
        if(w[number]!=w[num])   return  false;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<=n-1;i++)
    {
          cin>>a[i]>>c[i]; 
    }
    int number=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=a[i]-1;j++)
        {
            w[number]=c[i];
            number++;
        }
    }
    while( debate(number,0)!=true)
    {
        
    }
   return 0;
}