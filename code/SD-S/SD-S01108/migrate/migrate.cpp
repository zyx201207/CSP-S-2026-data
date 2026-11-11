#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000009];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=3 and d==1)cout<<"0\n";
		else if(c==11 or c==12){
			d/=(a[2]-a[1]);
			if(d==1)cout<<"0\n";
			else cout<<n-(d*2-1)+1<<"\n";
		}
		else if(c==13 or c==14){
			int l=0,js=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d and a[n]-a[i]<=d){
					if(!l)l=i;
					js++;
				}
			}
			if(js>=3)cout<<"0\n";
			else if(js==2){
				int x=0,y=n+1;
				while(a[x+1]+d<a[l+2])x++;
				while(a[y-1]-d>a[l-1])y--;
				cout<<x*y<<"\n";
			}
			else{
				int x=0,y=n+1,jsx=0,jsy=0;
				while(a[x+1]+d<a[l+1])x++;
				while(a[y-1]-d>a[l-1])y--;
				while(a[x+jsx+1]+d<a[l+2])jsx++;
				while(a[y-jsy-1]-d>a[l-2])jsy++;
				cout<<jsx*jsy<<"\n";
			}
		}
	}
	return 0;
}
