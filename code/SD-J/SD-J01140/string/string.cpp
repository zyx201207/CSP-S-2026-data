#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n;
LL a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int len=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=len;
		a[l]-=len;
		a[r]-=len;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans<<endl;
	return 0;
}
