#include<bits/stdc++.h>
using namespace std;
unsigned long long data[200010];
unsigned long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>data[i];
	}
	sort(data+1,data+n+1);
	ans=data[n];
	for(int i=1;i<m;i++){
		ans&=data[n-i];
	}
	cout<<ans<<'\n';
	return 0;
} 
