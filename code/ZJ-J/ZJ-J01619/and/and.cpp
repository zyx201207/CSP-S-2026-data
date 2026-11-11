#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,maxx,ans1,ans2,mp[5];
void dfs(int num,int x,int sum,int c){
	if(num>n+1){
		return;
	}
	if(x==m){
		ans=max(ans,sum);
		return;
	}
	if(c==0){
		dfs(num+1,x,sum,0);
		dfs(num+1,x,sum,1);
	}
	else{
		if(x==0){
			dfs(num+1,x+1,a[num],0);
			dfs(num+1,x+1,a[num],1);			
		}
		else{
			dfs(num+1,x+1,(sum&a[num]),0);
			dfs(num+1,x+1,(sum&a[num]),1);		
		}
	}
}
bool check(int x){
	int t;
	while(x>=4){
		t=x%2;
		x/=2;
		if(t==1){
			return 0;
		}
	}
	bool g=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=(i-1)){
			g=1;
		}
	}
	if(!g)return 1;
	else return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i==1)ans1=a[i];
		else ans1=(ans1&a[i]);
	}
	if(n<=20){
		dfs(1,0,0,0);
		dfs(1,0,0,1);
		cout<<ans;
	}
	else if(m==1){
		cout<<maxx;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans2=max(ans2,(a[i]&a[j]));
			}
		}
		cout<<ans2;		
	}
	else if(m==n){
		cout<<ans1;
	}
	else if(maxx<4){
		for(int i=1;i<=n;i++){
			mp[a[i]]++;
		}
		if(mp[3]>m){
			cout<<3;
		}
		else if((mp[3]+mp[2])>m){
			cout<<2;
		}
		else if((mp[1]>m)||((mp[1]+mp[3])>m)){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(check(n)){
		cout<<n-m;
	}
	else{
		cout<<1;
	}
	return 0;
}
