#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005][35],c[200005],s[35];
bool cmp(long long a,long long b){
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        long long j=0;
        while(a[i]>0){
            if(a[i]%2==0){
                b[i][j]=0;
            }
            else{
                b[i][j]=1;
            }
            a[i]/=2;
            j++;
        }
    }
    for(int i=1;i<=n;i++){
        c[i]=1;
    }
    for(int j=31;j>=0;j--){
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if(b[i][j]==1 and c[i]==1){
                cnt++;
            }
        }
        if(cnt>=m){
            s[j]=1;
            for(int i=1;i<=n;i++){
                if(b[i][j]!=1){
                    c[i]=0;
                }
            }
        }
    }
    long long j=1;
    for(int i=0;i<=31;i++){
        ans=ans+s[i]*j;
        j*=2;
    }
    cout<<ans;
    return 0;
}
