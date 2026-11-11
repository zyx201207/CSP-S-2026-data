#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
long long a[N],b[N],ans[N];
map<int,int>mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int T=n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int k=0;
	for(int i=1;i<=T;i++){
		a[i]=b[i+k];
		if(mp[a[i]]!=0){
			for(int j=mp[a[i]]+1;j<i;j++){
				ans[a[j]]=j-i;
				mp[a[j]]=0;
			}
			T=T-i+mp[a[i]];
			k+=i-mp[a[i]];
			i=mp[a[i]];
			
		}
		else{
			ans[a[i]]=0;
			mp[a[i]]=i;
		} 
	}
	for(int i=1;i<=n;i++){
		mp[b[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int an;
		an=mp[i]+ans[i];
		cout<<an<<" ";
	}
	return 0;
}

