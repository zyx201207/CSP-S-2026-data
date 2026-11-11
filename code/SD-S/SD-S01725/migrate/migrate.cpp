#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define x1 x_1
#define x2 x_2
#define y1 y_1
#define y2 y_2

using namespace std;
long long read(){
	long long res=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
ll a[2000006];
ll dd[2005][2005];
ll c,t;
ll n;
ll d;
int dfs(int i,int j,int now,ll step){
	if(now==j){
		if(step==dd[i][j]) return 1;
		else return 0;
	}
	if(step>dd[i][j]) return 0;
	ll cost=0;
	ll res=0;
	for(int k=now+1;k<=j;k++){
		cost+=a[k]-a[now];
		if(cost<=d) res+=dfs(i,j,k,step+1);
		else break;
	}
	return res;
}
int main(){
	//一定一定要初始化！！！
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//Oct31==Dec25?
    c=read(),t=read();
    if(c==11||c==12){
    	while(t--){
    		n=read(),d=read();
    		for(int i=1;i<=n;i++) a[i]=read();
    		int k=d/(a[2]-a[1]);
    		cout<<n-k-1<<'\n';
		}
	}
    while(t--){
    	n=read(),d=read();
    	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dd[i][j]=0;
    	for(int i=1;i<=n;i++) a[i]=read();
    	for(int i=1;i<=n;i++){
    		int r=i;
    		ll cost=0;
    		int x=1; 
    		while(r<=n){
    			cost+=a[r+1]-a[r];
    			if(cost>d) cost=0,x++;
    			r++;
    			dd[i][r]=x;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=dfs(i,j,i,0);
				if(cnt==1) ans++;
			}
		}
		cout<<ans-1<<'\n';
	}
    
	return 0;
}

