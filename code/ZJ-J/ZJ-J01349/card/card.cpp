#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=5e5+10;
int n,m,vis[N],pre[N],a[N],ans[N];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	L(i,1,n){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag){
		L(i,1,n) ans[a[i]]=i;
		L(i,1,m) cout<<ans[i]<<" ";
		return 0;
	}
	L(i,1,n){
		L(j,1,m) {
			pre[j]=0;
			vis[j]=0;
		}
		L(j,i,n){
			if(pre[a[j]]){
				L(k,pre[a[j]],j-1){
					vis[a[k]]=0;
					pre[a[k]]=0;
				}
			}
			vis[a[j]]=1;
			pre[a[j]]=j;
		}
//		cout<<i<<": "<<vis[1]<<"\n";
		L(j,1,m) ans[j]+=vis[j];
	}
	L(i,1,m) cout<<ans[i]<<" ";
	return 0;
}

