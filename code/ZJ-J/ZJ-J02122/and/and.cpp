#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,k[2005],maxx,t,ta[100],ck[100];
bool flag1=1;
bool fun(long long x){
	int c=1;
	for(int i=2;i<=30;i++){
		if(x==c-1){
			ta[i]++;
			return 1;
		}
		c*=2;
	}
	return 0;
}
void dfs(int deep,int u){
	if(deep>n&&u==m){
		ans=max(k[n],ans);
		return;
	}
	if(u>m||deep>n){
		return;
	}
	k[deep]=k[deep-1]&a[deep];
	dfs(deep+1,u+1);
	k[deep]=k[deep-1];
	dfs(deep+1,u);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i>1){
			t=t&a[i];
		}
		else
			t=a[i];
		flag1=min(flag1,fun(a[i]));
	}
	k[0]=2147483647;
	if(n<=20){//1~5
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	if(m==1){//6
		cout<<maxx;
		return 0;
	}
	if(m==n){//7
		cout<<t;
		return 0;
	}
	if(m==2){//8~10
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(maxx<4){//16~17
		for(int i=1;i<=n;i++){
			ck[a[i]]++;
		}
		if(ck[3]>=m)cout<<3;
		else if(ck[3]+ck[2]>=m)cout<<2;
		else if(ck[3]+ck[1]>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag1==1){//13
		int i=30,sum=0;
		while(sum<m){
			sum+=ta[i];
			i--;
		}
		int c=1;
		for(int j=2;j<=i;j++){
			c*=2;
		}
		cout<<c-1;
		return 0;
	}
	cout<<0;
	return 0;
}
