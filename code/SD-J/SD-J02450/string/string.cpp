#include<bits/stdc++.h> 
using namespace std;
int n,a[200010],l,r;
char c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	l=1,r=n;
	while(l<r){
		int minx=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=minx;
		}
		a[l]-=minx,a[r]-=minx;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
}
