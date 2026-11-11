#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long t[1000010];
long long b[510][200000];
long long c[510][200000];
long long tb[1000][1000];
int add(int a,int b,int c,int f,long long n ){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=t[i];++j){
            if(a==b[i][j] && (c-b)==b[i][f]){
                p+=c[i][j];
            }
            p+=2*c[i][f];
        }
    }
    return f;
}
int mazx(long long a,long long n){
    long long x=-1e15;
    for(long long i=1;i<=n;++i){
        for(long long j=1;j<=t[i];++j){
            if(a==b[i][j]){
                x=min(c[i][j],x);
            }
        }
    }
    return x;
}
int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        cin>>t[i];
        for(int j=1;j<=t[i];++j){
            cin>>b[i][j];
            cin>>c[i][j];
        }
    }
    long long ans=0;
    for(int i=1;i<=q;++i){
        long long t,k; cin>>t>>k;
        ans=a[t]+a[k];
        for(int j=1;j<=n;++i){
            for(int k=1;k<=t[i];++k){
               if(t==k){
                    ans+=mazx(t,n);
               }
            }

            long long flag=0;


        }

        cout<<ans<<endl;
    }
    return 0;
}
