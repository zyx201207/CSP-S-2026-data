#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int x=1,y=n;
	while(x<=y){
		int k=min(a[x],a[y]);
		if(b[x]!=b[y]){
			ans+=k;
		}
		a[x]-=k;
		a[y]-=k; 
		if(a[x]<=0){
			x++;
		}
		if(a[y]<=0){
			y--;
		}
	}
	cout<<ans;
	return 0;
}

