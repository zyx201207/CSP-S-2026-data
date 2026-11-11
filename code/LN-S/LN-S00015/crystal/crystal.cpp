#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[1000000],s=1,max=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long s1=0;
    for(int i=1;i<=n;i++)
    {
       s1=a[i]+m;
       for(int j=i+1;j<=n;j++)
       {
            if(a[j]<=s1)
            {
                s++;
            }
            else
            {
                if(s>=max)
                {
                    max=s;
                }
                s=1;
                break;
            }

       }
     	/*if(a[i]==a[i-1]&&m-m1>=1)
        {
            s++;
            s1+=a[i];
            m1+=1;
        }
       /* else if(a[i]==a[i-1]+1&&m-m1>=2)
       {
           s++;
           s1+=a[i];
           m1+=2;
       }
       else{
        for(int j=i;j<=n;j++)
        {
            if(a[j]>s1)
            {
                if(abs(a[j]-s1)<=abs(a[j-1]-s1)&&m-m1>=abs(a[j]-s1))
                {
                    s++;
                    s1+=a[j];
                    m1+=abs(a[j]-s1);
                    i=j+1;
                }
                else if(abs(a[j]-s1)>=abs(a[j-1]-s1)&&m-m1>=abs(a[j-1]-s1))
                {
                    s++;
                    s1+=a[j];
                    m1+=abs(a[j-1]-s1);
                    i=j;
                }
            }
        }
       }
       if(m-m1==0)
       {
           break;
       }*/

    }
    cout<<max;
    return 0;
}


