#include<bits/stdc++.h>
using namespace std;
const long long MAXN=20005;
int n;
int a[MAXN];
unsigned int dp[MAXN][MAXN];

char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    int cnt=1;
    cin>>a[1]>>c[1];
    for(int i=2;i<=n;++i){
        int ai;
        char ci;
        cin>>ai>>ci;
        //cout<<ai<<ci;
        if(ci==c[cnt]) a[cnt]+=ai;
        else{
            ++cnt;
            a[cnt]=ai;
            c[cnt]=ci;
        }
    }
    for(int i=1;i<=cnt;++i){
        dp[i][i]=0;
    }
    for(int len=2;len<=cnt;++len){
        for(int i=1;i<=cnt-len+1;++i){
            int j=i+len-1;
            if(len==2)dp[i][j]=min(a[i],a[j]);
            else{
                long long t=0;
                if(c[i]!=c[j])t=max(a[i],a[j]);
                else t=abs(a[i]-a[j]);
                dp[i][j]=dp[i+1][j-1]+t;
            }
        }
    }/*
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i){
        cout<<a[i]<<"&"<<c[i]<<" ";
    }cout<<"\n";*/
    cout<<dp[1][cnt];
    return 0;
}
