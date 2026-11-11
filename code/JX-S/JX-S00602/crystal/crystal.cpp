#include <bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define OI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N=5e5+5;
int a[N],s[N];
int n,m;
int ans;

signed main(){
	OI("crystal");
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(int i=1,j=1;j<=n;){
		int v=a[j]*(j-i)-(s[j-1]-s[i-1]);
		//cout<<v<<' '<<j-i+1<<endl;
		if(v<=m) ans=max(ans,j-i+1),j++;
		else if(v>m) i++;
	}
	cout<<ans<<endl;
	return 0;
}
