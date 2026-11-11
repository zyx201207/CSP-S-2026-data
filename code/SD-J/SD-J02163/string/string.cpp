#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],l,r,ans=0,mi;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	l=1,r=n;
	while(l<r){
		mi=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=mi;
		}
		a[l]-=mi,a[r]-=mi;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
