#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200005],number[200005],sum=-1;

void mark(int s){
    int p[12800];
    memset(p,0,sizeof(p));
    long long cnt=0;
    while(s){
        p[cnt]=s%2;
        s/=2;
        cnt++;
    }
    for(int i=0;i<cnt;i++){
        number[i]=number[i]+p[i];
    }
    sum=max(sum,cnt-1);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }

    for(long long i=1;i<=n;i++){
        mark(a[i]);
    }
    int y=0;
    for(long long i=sum;i>=0;i--){
        if(number[i]>=m&&y<m){
            long long s=1;
            for(long long j=1;j<=i;j++)s*=2;
            ans+=s;
            y++;
        }
        if(y==m)break;
    }
    cout<<ans;
    return 0;
}
