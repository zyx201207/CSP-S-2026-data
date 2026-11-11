#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;i++){
		while(j>i&&a[i]>0){
			if(c[i]!=c[j]) ans+=min(a[i],a[j]);
			if(a[i]>=a[j]) a[i]-=a[j--];
			else a[j]-=a[i],a[i]=0;
		}
	}
	cout<<ans;
	return 0;
}