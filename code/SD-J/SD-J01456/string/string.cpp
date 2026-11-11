#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n,ans,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]==0) i++;
		if(a[j]==0) j--;
		if(a[i]==a[j]&&c[i]==c[j]){i++,j--;continue;}
		if(i==j) break;
		if(i+1==j){
			if(c[i]==c[j]) break;
			else ans+=min(a[i],a[j]);
			i++,j--;
			continue;
		}
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]); 
		}
		if(a[i]<a[j]){a[j]-=a[i],i++;}
		else{a[i]-=a[j],j--;} 
	}
	cout<<ans;
	/*^_^*/
	return 0;
}

