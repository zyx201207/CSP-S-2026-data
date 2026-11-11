#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,t,n;
ll d,a[2000010];
int h;

bool checkb(){
	for(int i=1;i<=n;i++){
		ll x=a[i]-a[1],y=a[n]-a[i];
		if(d>=x&&d>=y){
			h=i;
			return true;
		}
	}
	return false;
}

bool check(int v,int w){
	int g=0;
	for(int i=v+1;i<w;i++){
		ll x=a[i]-a[v];
		ll y=a[w]-a[i];
		if(d>=x&&d>=y)g++;
	}
	if(g==2)return true;
	return false;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool fa=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2){
				if(a[i]+a[i-2]!=a[i-1]+a[i-1]){
					fa=false;
				}
			}
		}
		if(n>=3&&(fa||checkb())){
			cout<<n-3<<'\n';
		}
		else{
			ll cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;i+j<=n;j++){
					if(i+j>n)break;
					int k=i+j;
					if(check(j,k))cnt++;
				}
			}
			cout<<cnt<<'\n';
		}
	}
}

