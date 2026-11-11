#include<bits/stdc++.h>
using namespace std;
struct node{
	int s[35];
	int bh;
};
int n,m,a[200000+10]; 
node b[200000+10];
int cf[40];
void dfs(int now,int sum){
	for(int i=0;i<=30;i++){
		b[sum].s[i]=0;	
	}
	for(int i=30;i>=0;i--){
		if(cf[i]<=now){
			now-=cf[i];
			b[sum].s[i]=1;
		}
	}
	return ;
}
bool cmp(node x,node y){
	for(int i=30;i>=0;i--){
		if(x.s[i]>y.s[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cf[0]=1;
	for(int i=1;i<=30;i++){
		cf[i]=cf[i-1]*2;
	} 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dfs(a[i],i);
		b[i].bh=a[i];
	}
	sort(b+1,b+n+1,cmp);
	int ans=b[1].bh;
	for(int i=2;i<=m;i++){
		ans&=b[i].bh;
	}
	cout<<ans;
	return 0;
}
