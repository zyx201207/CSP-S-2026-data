#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],d[200005][32];

bool cmp(int a,int b){
	return a>b;
}
bool theA(){
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		while(x%2==0)x/=2;
		if(x>0)return false;
	}
	return true;
}
bool theB(){
	for(int i=2;i<=n;i++){
		if(a[i-1]!=a[i]+1)return false;
	}
	return true;
}
int ans;
void dps(int w,int v,int u){
	if(u>m){
		ans=max(ans,v);
		return ;
	}
	dps(w+1,v,u);
	dps(w+1,v&a[w],u+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dps(1,pow(2,20)-1,0);
		cout<<ans;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				x=max(x,a[i]&a[j]);
			}
		}
		cout<<x;
		return 0;
	}
	if(m==n){
		int x=pow(2,20)-1;
		for(int i=1;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(theA()){
		cout<<a[m];
		return 0;
	}
	if(theB()){
		if(m*2>=n)cout<<0;
		else{
			int x=n-1;
			for(int i=1;i<m;i++){
				x&=n-i;
			}
			cout<<x;
		}
		return 0;
	}
	if(a[1]<=4){
		int x;
		for(int i=1;i<=n;i++){
			if(a[i-1]==3&&i>m){
				cout<<3;
				return 0;
			}
			if(a[i-1]==2&&i>m){
				cout<<2;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){//10->2
		int x=a[i];
		for(int j=1;j<=30;j++){
			if(x<=0)break;
			d[i][j]=x%2;
			x/=2;
		}
	}
	if(m+1==n){
		int w[32]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=30;j++){
				w[j]+=d[i][j];
			}
		}
		int x=0;
		for(int i=1;i<=n;i++){
			int u=0;
			for(int j=1;j<=30;j++){
				u*=2;
				if(w[j]-d[i][j]==n-1){
					u++;
				}
			}
			x=max(x,u);
		}
		cout<<x;
		return 0;
	}
	return 0;
} 
