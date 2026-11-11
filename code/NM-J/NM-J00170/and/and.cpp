#include<iostream>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,y;
    int sum,num=0,mum=0,hum;
    cin>>a>>b;
    int x[a];
    for(int i=1;i<=a;i++)
    {
        cin>>y;
        x[i-1]=y;
    }
    for(int j=0;j<b;j++)
    {
        for(int i=0;i<a;i++)
        {
            for(int k=0;k<a;k++)
            {
                sum=x[i]&x[k];
                if(sum>num)
                {
                    num=sum;
                }
            }
        }
        if(j=0)
        {
            mum=num;
        }
        hum=mum&num;
        mum=num;
    }
    cout<<hum;
    return 0;
}