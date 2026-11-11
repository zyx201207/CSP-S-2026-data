#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;

int s[200005];
int flag[2005][2005];

int dg(int i,int d){
	int x=s[i];
	if(d==m) return x;
	for(int j=i+1;j<=n-m+1;j++){
		int g=x;
		if(flag[j][d+1]==0x3f3f3f3f3f3f3f3f) flag[j][d+1]=dg(j,d+1);
		g&=flag[j][d+1];
		x=max(x,g);
	}
	
	return x;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);//Мо 
	freopen("and.out","w",stdout);//Мо 
	memset(flag,0x3f,sizeof(flag));
	cin>>n>>m;
	int x;
	
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(i==1) x=s[i];
		x&=s[i];
		s[i]*=-1;
	}
	
	if(m==n){
		cout<<x;
		return 0;
	} 
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		s[i]*=-1;
	}
	if(m==1){
		cout<<s[1];
		return 0;
	} 
	int t=s[1];
	int cnt=0;
	if(m<=4){
		for(int i=1;i<=n;i++){
			cnt++;
			if(s[i]!=s[1]) t&=s[i];
			if(i==m){
				cout<<t;
				return 0;
			}
			
		}
	}
	
	int f=0;
	for(int i=1;i<=n-m+1;i++){
		f=max(f,dg(i,0));
	}
	cout<<f;
	return 0;
}
