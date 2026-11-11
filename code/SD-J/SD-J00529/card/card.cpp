#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5,M=3e5+5;
int a[N],b[M],cnt[M];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		mp.clear();
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				mp[a[j]]=j;
			}else{
				for(int k=mp[a[j]]+1;k<=j-1;k++){
					b[a[k]]=0;
				}
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

