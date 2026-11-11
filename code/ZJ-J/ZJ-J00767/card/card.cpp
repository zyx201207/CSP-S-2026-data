#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int dis[M];
int ans[N];
map<int,int> mp;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int ju=1;ju<=n;ju++){
		memset(dis,0,sizeof(dis));
		memset(ans,0,sizeof(ans));
		int id=1;
		for(int i=ju;i<=n;i++){
			if(dis[a[i]]!=0){
				for(int j=dis[a[i]]+1;j<=id;j++){
					dis[ans[j]]=0;
					ans[j]=0;
				}
				id=dis[a[i]];
		    }else{
				ans[++id]=a[i];
				dis[a[i]]=id;
			}
		}
		for(int i=1;i<=id;i++){
			mp[ans[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
    return 0;
}
