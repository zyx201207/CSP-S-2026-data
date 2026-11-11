#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	char c;
	long long a[n+5][2],l=1,r=n,ans=0;
	for(int i = 1;i <= n ;i++){
		cin>>a[i][1]>>c;
		a[i][2]=int(c);
	}
	while(l<r){
		int p = min(a[l][1],a[r][1]);
		if(a[l][2]!=a[r][2]){
			ans+=p;
		}
		a[r][1]-=p;
		a[l][1]-=p;
//		cout<<r<<" "<<a[r][1]<<" "<<l<<" "<<a[l][1]<<" "<<ans<<endl;
		if(a[r][1]==0) r--;
		if(a[l][1]==0) l++;
	}
	cout<<ans;
	return 0;
}