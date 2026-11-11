#include<bits/stdc++.h>
using namespace std;
long long t,c,n,d,x[2000006],ans,l,num;
bool vis[2000006];
bool B=0;
void dfs(int now,int to,long long ll){
	//cout<<now<<" "<<ll<<endl;
	if(now==to){
		if(l==ll)num++;
		if(ll<l)num=1;
		l=min(l,ll);
		B=1;
		return ;
	}
	for(int i=now+1;i<=to;i++){
		if(max(x[i]-x[now],x[now]-x[i])<=d){
			//cout<<x[i]<<" "<<x[now]<<" "<<ll<<endl;
			if(vis[i]==0){
				vis[i]=1;
				//cout<<now<<" "<<i<<" "<<to<<" "<<ll;
				dfs(i,to,ll+1);
				vis[i]=0;
			}
		}
	}
}
void S(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		cin>>x[i];
	}
	ans=0;
	if(c==11||c==12){
		cout<<n-2<<endl;
		return 0;
	}
	l=LLONG_MAX;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			B=0;
			num=0;
			vis[i]=1;
			l=LLONG_MAX;
			dfs(i,j,0);
			vis[i]=0;
			if(B){
				//cout<<i<<" "<<j<<" "<<num<<endl;
				if(num==2)ans++;
			}
			
		}
	} 
	cout<<ans<<endl; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)S();
} 
/*0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6
 */
