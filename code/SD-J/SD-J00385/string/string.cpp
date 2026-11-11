#include<bits/stdc++.h>
using namespace std;
int n,a[200009];long long ans;char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		b[i]-='a';
	}
	int l=1,r=n;
	while(l<r){
		//		cout<<l<<" "<<r<<"\n";
		char x=b[l],y=b[r];int mn=min(a[l],a[r]);
	//	cout<<mn<<"\n";
		if(x!=y){
		//	cout<<ans<<" "<<mn<<" "<<ans+mn<<"\n";
			ans+=mn;
		}
		a[l]-=mn;
		a[r]-=mn;
		if(a[l]==0)
		l++;
		if(a[r]==0)
		r--;
	}
cout<<ans;
return 0;
} 
