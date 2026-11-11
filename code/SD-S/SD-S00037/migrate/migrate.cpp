#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int c,t,a[N],n,d,ans;
bool check(int x,int y){
	if(y==x+1||y==x+2) return 0;
	int tot=0;
	for(int i=x;i<=y;i++)
		if(a[i]-a[x]<=d&&a[y]-a[i]<=d) tot++;
	if(tot==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(check(i,j)) ans++;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
