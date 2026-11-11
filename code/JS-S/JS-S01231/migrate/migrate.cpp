#include<bits/stdc++.h>
using namespace std;
int ans;
int cnt[10010][10010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> a;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            a.push_back(k);
        }
        int mini=a[n-1]-a[0];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int k=j;k<=n;k++){
                    if((abs(a[i]-a[j])<=d)&&(abs(a[i]-a[k])<=d)&&(abs(a[j]-a[k])<=d)&&i==1&&k==n)
                    cnt[i][k]+=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
                for(int k=1;k<=n;k++){
                    if(cnt[i][k]!=0)ans++;
                }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
