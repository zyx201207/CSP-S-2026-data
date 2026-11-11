#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005],t[500005],l[500005],ll[500005];
map<int,int>v[500005];
int n,m,ans[500005],maxx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]][++t[a[i]]]=i;
	}
	for(int j=1;j<=n;j++){
		l[a[j-1]]++;
		for(int i=1;i<=m;i++){
			ll[i]=l[i];
		}
		for(int i=j;i<=n;i++){
			if((t[a[i]]-ll[a[i]]>=1)){
				i=v[a[i]][++ll[a[i]]]-1;
			}
			else{
				ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
