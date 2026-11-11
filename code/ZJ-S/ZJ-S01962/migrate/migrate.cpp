#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define a first
#define b second
using namespace std;
const int N=2e6+10;
const bool ckr=0;

ll c,t,n,d,x[N],ans;
pll dis[3100][3100];

void solve(){
	n=ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	memset(dis, 0x3f ,sizeof dis);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]={0,1};
			if(abs(x[i]-x[j])<=d)dis[i][j]={1,1};
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j].a==dis[i][k].a+dis[k][j].a)dis[i][j].b+=dis[i][k].b*dis[k][j].b;
				else if(dis[i][j].a>dis[i][k].a+dis[k][j].a)dis[i][j].a=dis[i][k].a+dis[k][j].a,dis[i][j].b=dis[i][k].b*dis[k][j].b;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j].b==2)ans++;
		}
	}
	cout<<ans/2<<endl;
	return ;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--)solve();

	

	return 0;
}

