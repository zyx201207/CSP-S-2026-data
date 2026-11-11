#include<iostream>
#include<stack>
using namespace std;
stack<int> v;
int change(int number)
{
    int number1=0;
    while(number>0)
    {
        v.push(number%2);
        number1=number1*10+number%2;
        number=number/2;
    }
    return 0;
}
int num[100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    int zhong;
    for(int i=0;i<=n-1;i++)
    {
        cin>>num[i];
    }
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            if(num[i]>num[j])
            {
                zhong=num[i];
                num[i]=num[j];
                num[j]=zhong;
            }
        }
    }
    int number=change(num[0]),he=number;
    for(int i=1;i<=m-1;i++)
    {
        change(num[i]);
        while(!v.empty())
        {
            number=number*10+v.top();
            v.pop();
        } 
        he=number;
        number =he and number;
       
    }
    cout<<he;
}