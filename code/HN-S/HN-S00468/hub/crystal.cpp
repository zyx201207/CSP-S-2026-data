#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int main(){
    ll n,m,a[N],b[N];
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll res=m,ans=0;
    b[1]=0;b[n+1]=0x3f;
    for(int j=1;j<=n;j++){
		for(int i=j+1;i<=n;i++){
			b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
    }
		for(int i=1;i<=n;i++){
			if((res==b[i]&&res<b[i+1])||(res>b[i]&&res<b[i+1])){
				ans=i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
