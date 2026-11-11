#include<bits/stdc++.h>
using namespace std;
void read(long long &x){
	x=0;
	bool xx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			xx=1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	if(xx){
		x=-x;
	}
}
long long n,m,a[200005];
long long ans;
void dfs(int x,int y,long long z){
	if(y==m){
		ans=max(ans,z);
		return;
	}
	if(x>n||m-y>n-x+1){
		return;
	}
	for(int i=x;i<=n-(m-y-1);i++){
		int xxx=z;
		xxx&=a[i];
		dfs(i+1,y+1,xxx);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		long long x;
		read(x);
		ans=x;
		for(int i=2;i<=n;i++){
			read(x);
			ans&=x;
		}
		cout<<ans;
		return 0;
	}else if(m==1){
		long long x;
		for(int i=1;i<=n;i++){
			read(x);
			ans=max(ans,x);
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				long long xxx=a[i];
				xxx&=a[j];
				ans=max(ans,xxx);
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		for(int i=1;i<=n-m+1;i++){
			dfs(i+1,1,a[i]);
		}
		cout<<ans;
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/