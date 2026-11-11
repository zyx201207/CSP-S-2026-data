#include<bits/stdc++.h>
using namespace std;
struct ss{
    long long x,y;
}a[500005];
bool cmp(ss a,ss b){
    return a.y<b.y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i].x;
    }
    long long flag=0,minn=1000000000000;
    for(long long i=1;i<=n;i++){
        flag=0;
        for(long long j=1;j<=n;j++){
            flag=flag+abs(a[i].x-a[j].x);
        }
        if(flag<minn){
            minn=flag;
            for(long long j=1;j<=n;j++){
                a[j].y=abs(a[i].x-a[j].x);
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++){
        if(m>=a[i].y){
            a[i].x+=a[i].y;
            m-=a[i].y;
            cnt++;
        }
        else{
            cout<<cnt;
            return 0;
        }
    }
    return 0;
}
