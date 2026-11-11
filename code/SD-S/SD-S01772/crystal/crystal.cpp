#include<bits/stdc++.h>
typedef long long ll; 
using namespace std;
const int N=5e5+20;
ll n,a[N],m,sum[N],u[N],vis[N];
struct node{
	ll u,num;
}t[N];
bool cmp(node x,node y){
	return x.u<y.u;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		if(i!=n){
			u[i]=a[i+1]-a[i];
			sum[i]=sum[i-1]+u[i];
			t[i].u=u[i];
			t[i].num=i;
		}
	}
	ll ans=1;
	sort(t+1,t+n,cmp); 
//	for(ll i=1;i<=n;i++){
//		cout<<t[i].u<<' '<<t[i].num<<'\n';		
//	}
	for(ll i=1;i<n;i++){
		if(!vis[t[i].num]){
			vis[t[i].num]=1;
			ll x=t[i].num,y=t[i].num;
			ll tot=0,op=1;
			tot=t[i].u;
			while(tot<m){
				if((x-1>=1&&tot+sum[y]-sum[x-2]<=m)&&(y+1<n&&tot+u[y+1]*(op+1)<=m)){
					if(sum[y]-sum[x-2]<=u[y+1]*(op+1)){
						tot+=sum[y]-sum[x-2];
						op++;
						x--; 
//						vis[x]=1;&&!vis[x-1]&&!vis[y+1]
					} 
					else{
						tot+=u[y+1]*(op+1);
						op++;
						y++;
//						vis[y]=1;
					}
				}
				else if(x-1>=1&&tot+sum[y]-sum[x-2]<=m){
					tot+=sum[y]-sum[x-2];
					op++;
					x--; 
//					vis[x]=1;
				}
				else if(y+1<n&&tot+u[y+1]*(op+1)<=m){
					tot+=u[y+1]*(op+1);
					op++;
					y++;
//					vis[y]=1;&&!vis[y+1]&&!vis[x-1]
				}
				else break;
			}
			ans=max(ans,op+1);
		}
	}
	cout<<ans;
	return 0;
}
/*
6 18
-19 -1 2 2 7 9
*/

