#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum,maxx=1,b;
    cin>>n>>m;
    long long a[n+10]={};
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]){
                sum=a[i];a[i]=a[j];a[j]=sum;
            }
    for(int i=n;i>1;i--){
        sum=1;
        b=m;
        for(int j=i-1;j>=1;j--){
            b=b-(a[i]-a[j]);
            if(b<0)
                break;
            sum++;
            if(sum>maxx)
                maxx=sum;
        }
    }
    cout<<maxx;
    return 0;
}
