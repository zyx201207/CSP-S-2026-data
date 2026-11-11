#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int rreach[2000010],lreach[2000010];
int routes[2000010][2];
void dfs(int t,int l,int former){
	if(routes[t][0]>l){
		routes[t][0]=l;
		routes[t][1]=1;
	}
	else if(routes[t][0]==l){
		routes[t][1]+=former;
		if(routes[t][1]>2)return;
	}
	else{
		return;
	}
	for(int i=lreach[t];i<=rreach[t];i++){
		if(i==t)continue;
		dfs(i,l+1,routes[t][1]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(c==11 || c==12){
			if(3*(x[1]-x[0])>d){
				cout<<0;
			}
			else if(2*(x[1]-x[0])<=d){
				cout<<n*(n-1);
			}
			else{
				cout<<0;
			}
		}
		for(int i=0;i<n;i++){
			lreach[i]=lower_bound(x,x+n,x[i]-d)-x;
			if(lreach[i]==n)lreach[i]=0;
			rreach[i]=upper_bound(x,x+n,x[i]+d)-x-1;
			if(rreach[i]==n)rreach[i]=n-1;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				routes[j][0]=INT_MAX;
				routes[j][1]=0;
			}
			for(int q=lreach[i];q<=rreach[i];q++){
				dfs(q,1,1);
			}
			for(int j=i;j<n;j++){
				if(routes[j][1]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}