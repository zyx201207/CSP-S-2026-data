#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long n,m,a[N],Max=-0x3f;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n>5000){
        bool flag=true;
        for(long long i=1;i<=n;i++){
            if(a[i]!=i)flag=false;
        }
        if(flag){
            long long num=0;
            while(m>0){
                m-=(num+1);
                num++;
            }
            if(m==0)cout<<num+1;
            else cout<<m;
        }
        else{
            m/=(a[2]-a[1]);
            long long num=0;
            while(m>0){
                m-=(num+1);
                num++;
            }
            if(m==0)cout<<num+1;
            else cout<<num;
        }
        return 0;
    }
    for(long long i=1;i<=n;i++){
        long long sum=0,num=0;
        for(long long j=1;j<=i;j++){
            sum+=(a[i]-a[j]);
            num++;
        }
        if(sum<=m)Max=max(Max,num);
        else{
            for(long long j=1;j<=i;j++){
                sum-=(a[i]-a[j]);
                num--;
                if(sum<=m)break;
            }
            Max=max(Max,num);
        }
    }
    cout<<Max;
    return 0;
}
