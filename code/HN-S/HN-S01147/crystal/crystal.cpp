#include<bits/stdc++.h>
using namespace std;
#define int long long
int an[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
	}
	sort(an+1,an+1+n);
	for(int i=1;i<=n;i++){
		if(m<0){
			cout<<i-1;
			return 0;
		}
		if(i!=n)m-=i*(an[i+1]-an[i]);
	}
	cout<<n;
	return 0;
}
