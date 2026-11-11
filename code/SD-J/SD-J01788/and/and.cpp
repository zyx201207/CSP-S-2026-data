#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		ans=max(ans,a);
	}
	cout<<ans;
	return 0;
}

