#include<bits/stdc++.h>
using namespace std;

char c[200020];
int a[200020];
int l,r,n;
long long ans;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(r-l){
		if(c[l]==c[r]){
			int minn=min(a[l],a[r]);
			a[l]-=minn,a[r]-=minn;
		}else{
			int minn=min(a[l],a[r]);
			a[l]-=minn,a[r]-=minn;
			ans+=minn;
		}
		if(a[r]==0) r--;
		if(a[l]==0) l++;
	}
	cout<<ans;
	return 0;
}