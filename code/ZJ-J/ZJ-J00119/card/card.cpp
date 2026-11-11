#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+10;
ll a[N],n,m,k[N],pre[N],ans[N],pd[N];
struct node{
	ll num,pos;
}c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		memset(k,0,sizeof(k));
		memset(pre,0,sizeof(pre));
		memset(c,0,sizeof(c));
		memset(pd,0,sizeof(pd));
		for(ll j=i;j<=n;j++){
			if(c[a[j]].num&&pre[c[a[j]].pos]>=0){
				cout<<c[a[j]].pos<<" "<<j<<endl;
				k[c[a[j]].pos]=-1;
				k[j]=1;
				c[a[j]].pos=j;
				c[a[j]].num=0;
			}
			else {
				c[a[j]].num=1;
				c[a[j]].pos=j;
			}
			for(ll q=i;q<=n;q++){
				pre[q]=pre[q-1]+k[q];
			}
		}
		for(ll j=i;j<=n;j++){
			if(pre[j]>=0&&!pd[a[j]]){
				ans[a[j]]++;
				cout<<a[j]<<" a";
				pd[a[j]]=1;
			}
		}
	}for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
}


