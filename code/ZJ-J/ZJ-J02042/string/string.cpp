#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],c[200005],n,l,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char x;
		cin>>x;
		c[i]=x-'a'+1;
		l+=a[i];
	}
	int x=1,y=n;
	while(x<y){
		if(a[x]<a[y]){
			if(c[x]!=c[y])ans+=a[x];
			a[y]-=a[x];
			x++;
		}
		else if(a[x]==a[y]){
			if(c[x]!=c[y])ans+=a[y];
			x++;y--;
		}
		else{
			if(c[x]!=c[y])ans+=a[y];
			a[x]-=a[y];
			y--;
		}
	}
	cout<<ans;
	return 0;
}
