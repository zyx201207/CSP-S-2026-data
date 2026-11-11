#include <bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
long long  a[N],pos[N],s[N];
long long sum=0;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		pos[i]=a[i+1]-a[i];
	}
	
	for (int i=1;i<n;i++){
		s[i]=s[i-1]+pos[i]; 
	}
	int zans=0;
	for (int l=1;l<n;l++){
		int r=l+1;
		zans=1;
		while (r<=n) {
			if (s[r]-s[l-1]<=m){
				zans++;
				r++;
			} else {
				break;
			}
		}
		ans=max(ans,zans);
	}
	cout<<ans;
	return 0;
}





