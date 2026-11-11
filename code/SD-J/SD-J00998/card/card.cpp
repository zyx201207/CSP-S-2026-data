#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
const int N=1e6+10,M=1e9+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N],b[N];
map<int,int> mp;
signed main(){
	fst;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			int idx=0;
			for(int j=1;j<=i;j++){
				if(a[j]==a[i]&&a[j]!=0){
					idx=j;
					break;
				}
			}
			if(idx){
				for(int j=idx;j<i;j++){
					a[j]=0;
				}
			}
		}
		if(a[k]!=0){
			mp[a[k]]++;
		}
		for(int i=k+1;i<=n;i++){
			mp[a[i]]++;
			a[i]=b[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}

