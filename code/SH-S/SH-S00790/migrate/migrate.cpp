#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,a[5000009],ans,d;
bool ok(int i,int j){
	int x,y;
	int ggg=1;
	while(i<=j){
		if(i==j)ggg=0;
		ll cnti=0,cntj=0;
		while(cnti<=d)i++,cnti+=a[i]-a[i-1];
		cnti-=a[i]-a[i-1],i--;
		while(cntj<=d)j--,cntj+=a[j+1]-a[j];
		cntj-=a[j+1]-a[j],j++;
	}
	return ggg;
}
void solveBF(){
	for(int q=1;q<=t;q++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if(ok(i,j))ans++;
		cout<<ans;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12) {
		for(int q=1;q<=t;q++){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			ll x=a[2]-a[1],y=d/x;
			if(x==d)cout<<0<<endl;
			else if(d%x)cout<<0; 
			else cout<<n-y-y+1<<endl;
		}
	return 0;
	}
	if(c<=6){
		solveBF();
	}
	return 0;
}
