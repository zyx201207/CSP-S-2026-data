#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll n,m,a[N],len[N],b[N];
ll vis[N];
int flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=1;
		}
	}
	if(flag){
		int t=n;
		while(t--){
			int mj=1;
			memset(b,0,sizeof b);
			for(int i=n-t;i<=n;i++){
				flag=0;
				if(i!=n-t){
					for(int j=mj;j>=1;j--){
						if(a[i]==b[j]){
							mj=j;
							b[mj++]=a[i];
							flag=1;	
							break;
						}
					}
					if(!flag){
						b[mj++]=a[i];
					}
				}
				else{
					b[mj++]=a[i];
				}
			}
			for(int i=1;i<mj;i++){
				vis[b[i]]++;
			}
		}
	}
	else if(!flag){
		for(int i=1;i<=n;i++){
			len[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			vis[i]=len[i]+vis[i-1];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
} 
