#include<bits/stdc++.h>
using namespace std; 
const int MAXN = 1e6 +5;
long long int a[MAXN];
char c[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int cnt=min(a[r],a[l]);
		a[l]-=cnt;
		a[r]-=cnt;
		if(c[l]!=c[r]){
			ans+=cnt;
		}
		if(a[l]==0)l++;
		else r--;
	}
	cout<<ans;
	return 0;
}
