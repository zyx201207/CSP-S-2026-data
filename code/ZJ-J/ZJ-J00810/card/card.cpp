#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,cnt[300005],a[N];
map<int,int> ma;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int c=a[j];
			if(ma.count(c)){
				if(ma[c]==0)ma[c]=j;
				else{
					for(int k=ma[c];k<j;k++)ma[a[k]]=0;
					ma[c]=j;
				}
			}
			else ma[c]=j;
		}
		for(int i=1;i<=m;i++)if(ma.count(i)&&ma[i]!=0)cnt[i]++;
		ma.clear();
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
