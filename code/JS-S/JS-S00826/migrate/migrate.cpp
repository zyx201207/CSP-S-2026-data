#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
int n;
ll d;
ll a[2000060];
int pre[2000060],num[2000060][2];
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        int idx=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            while(a[i]-d>a[idx])idx++;
            pre[i]=idx;
        }
        pre[1]=0;
        ll ans=0;
        memset(num,0,sizeof(num));
        for(int i=n;i>=1;i--){
            if(i-pre[i]==1)num[i-1][0]=num[i][0]+1;
            else {
                num[i-1][0]=0;
                num[i][1]=0;
                for(int j=1;j<=num[i][0];j++)num[i+j][1]=j;
            }
        }
        for(int j=1;j<=num[1][0];j++)num[1+j][1]=j;
        for(int i=n;i>=1;i--){
            int A=pre[pre[i]+1];
            if(pre[pre[i]+1]<pre[i]){
                bool flag=1;
                for(int j=i-1;j>pre[i]+1;j--)if(pre[j]==A)flag=0;
                if(flag)ans+=(num[i][0]+1)*(num[pre[pre[i]+1]][1]+1);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
