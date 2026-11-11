#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int n,m,a[620001];
int mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,cos=0;
	for(int r=1;r<=n;r++){
		while(cos>m){
			cos-=(a[r]-a[l]); 
			l++;
		}
		mx=max(mx,r-l+1);
		cos+=(r-l+1)*(a[r+1]-a[r]);
	}
	cout<<mx;
	return 0;
}
