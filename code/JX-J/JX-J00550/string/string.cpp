#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
char c[N];
unsigned long long ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<=r){
		int ls=a[l],rs=a[r];
		if(ls==rs){
			if(c[l]!=c[r]) ans+=ls;
			l++;
			r--;
		}else if(ls>rs){
			if(c[l]!=c[r]) ans+=rs;
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r]) ans+=ls;
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans<<'\n';
    return 0;
}
