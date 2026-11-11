#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans,x,cnt;
bool a[N][31],f[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;f[i]=1;
        vector<int> e;
        while(x>0){
            e.push_back(x%2);
            x/=2;
        }
        int j=30;
        for(int v:e){
            a[i][j--]=v;
        }
    }

    for(int i=0;i<=30;i++){
        cnt=0;
        for(int j=0;j<n;j++) {
            if(a[j][i]==1&&f[j]==1){
                cnt++;
            }

        }
        if(cnt>=m){
            for(int j=0;j<n;j++) {
                if(a[j][i]==0){
                    f[j]=0;
                }

            }
            ans+=pow(2,30-i);
        }
    }
    cout<<ans;
    return 0;
}

