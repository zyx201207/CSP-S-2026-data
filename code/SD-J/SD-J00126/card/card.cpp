#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=5e5+10;
int a[N];
int st[N<<1],top;
bool vis[N];
int cnt[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		memset(vis,0,sizeof(vis));
		top=0;
		rep(j,i,n){
			if(!vis[a[j]]){
				st[++top]=a[j];
				rep(k,1,top){
					if(st[k]==a[j]){
						top=k;
						rep(z,k,top){
							vis[st[z]]=1;
						}
						break;
					}
				}
			}
		}
		rep(i,1,top){
			cnt[i]++;
		}
	}
	rep(i,1,m){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

