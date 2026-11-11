#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],ans;
char b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m = n-1;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i = 0;i<n;){
		if(i >= m) break;
		if(b[i] == b[m]){
			int aa = min(a[i],a[m]);
			a[i]-=aa;
			a[m]-=aa;
			//cout<<ans<<" ";
			if(a[m] == 0) m--;
			//cout<<m;
			if(a[i] == 0) i++;
		}
		else{
			int aa = min(a[i],a[m]);
			a[i]-=aa;
			a[m]-=aa;
			ans+=aa;
			//cout<<ans<<" ";
			if(a[m] == 0) m--;
			if(a[i] == 0) i++;
			
		}
	}
	cout<<ans;
	return 0;
}
