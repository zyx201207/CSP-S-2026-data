#include<bits/stdc++.h>
using namespace std;
long long v[500010];
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+1+n);
	long long a=0;
	int l=1,ans=1;
	for(int i=2;i<=n;i++){
		while(a+(i-l)*(v[i]-v[i-1])>m){
			a-=v[i-1]-v[l];
			l++;
		}
		a+=(i-l)*1ll*(v[i]-v[i-1]);
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
} 
