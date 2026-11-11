#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,x[2000005];
int p[5005][5005],mn[5005][5005];
void solve0(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>x[i];
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				mn[i][j]=10000000;
				p[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)	continue;
			mn[i][j]=(abs(x[i]-x[j])<=d? 1:10000000);
			p[i][j]=(abs(x[i]-x[j])<=d? 1:10000000);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!p[i][k]||!p[k][j])	continue;
				if(mn[i][j]>mn[i][k]+mn[k][j]){
					mn[i][j]=mn[i][k]+mn[k][j];
					p[i][j]=1;
				}
				else if(mn[i][j]==mn[i][k]+mn[k][j])	p[i][j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(p[i][j]==2)	{
//				cout<<i<<" "<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>x[i];
	sort(x+1,x+n+1);
	if(d<(x[n]-x[n-1])*2)	cout<<0<<'\n';
	else	cout<<(long long)n*(n-1)/2<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		if(c<=10)	solve0();
		if(c==11||c==12)	solve1();
	}
	return 0;
}