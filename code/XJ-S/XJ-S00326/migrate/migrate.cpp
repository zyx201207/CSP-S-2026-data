#include<bits/stdc++.h>
using namespace std;

#define int long long

int c,T;
int n,d,now,nowmin;
int a[2000005];

void DFS1(int x,int y,int s){
	if(x==y)
		nowmin=min(s,nowmin);
	
	for(int i=x+1;i<=y;i++)
		if(a[i]-a[x]<=d)
			DFS1(i,y,s+1);
	
}

void DFS2(int x,int y,int s){
	if(x==y&&s==nowmin)
		now++;
	
	for(int i=x+1;i<=y;i++)
		if(a[i]-a[x]<=d)
			DFS2(i,y,s+1);
	
}

void solve(){
	int ans=0;
	
	cin>>n>>d;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			nowmin=INT_MAX;
			now=0;
			DFS1(i,j,0);
			DFS2(i,j,0);
			if(now==2){
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	
	cout<<ans<<'\n';
}

void solve2(){
	cin>>n>>d;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	int t=a[2]-a[1];
	
	if(t>d)
		cout<<0<<'\n';
	else if(d/t==1)
		cout<<0<<'\n';
	else
		cout<<(((n-(d/t)*2+1)<=0)?0:(n-(d/t)*2+1))<<'\n';
	
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    cin>>c>>T;
    if(c==1||c==2){
    	while(T--)
    		solve();
	}
	else{
		while(T--)
			solve2();
	}
	
	return 0;
}
