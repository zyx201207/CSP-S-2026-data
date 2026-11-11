#include<bits/stdc++.h>
using namespace std;
int a[200100];
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,i,j;
	long long ans=0;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(i=1,j=n;i<j;){
		int t=min(a[i],a[j]);
		a[i]-=t;
		a[j]-=t;
		if(c[i]!=c[j]) ans+=t;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
} 
