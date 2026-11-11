#include<bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;
int n,m,ans;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	int x=1,y=n;
	while(x<y){
		if(c[x]!=c[y]){
			ans+=min(a[x],a[y]);
		}
		if(a[x]>a[y]){
			a[x]-=a[y];
			y-=1;
		}
		else{
			a[y]-=a[x];
			x+=1;
		}
	}	
	cout<<ans;
	return 0;
}
