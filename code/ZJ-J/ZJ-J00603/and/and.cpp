#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
bool flag[N];
int n,m;
signed main(void){
	IOS;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        flag[i]=1;
    }
    int ans=0;
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(flag[j]==1&&((a[j]>>i)&1)==1){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if(flag[j]==1&&((a[j]>>i)&1)==0){
                    flag[j]=0;
                }
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
