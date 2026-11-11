#include<bits/stdc++.h>
using namespace std;
int a[200007];
char b[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int l=1,r=n;
	long long int ans=0;
	while(l<r){
		int change=min(a[l],a[r]);
		if(b[l]!=b[r]) ans+=change;
		a[l]-=change;
		if(a[l]==0) l++;
		a[r]-=change;
		if(a[r]==0) r--;
	}
	cout<<ans;
}