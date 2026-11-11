#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
}
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast_read();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j])ans+=min(a[i],a[j]);
		if(a[i]>a[j])a[i]-=a[j--];
		else if(a[i]<a[j])a[j]-=a[i++];
		else i++,j--;
	}
	cout<<ans;
	return 0;
}
