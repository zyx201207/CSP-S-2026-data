#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],k;
pair<int ,int > l[300005];
int t[300005],mt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		memset(t,0,sizeof(t));
		for(int j=i,r=1;j<=n;j++){
			if(t[a[j]]!=0){
				for(int p=t[a[j]];p>=r;p--)	t[a[p]]=0;
				for(int i=1;i<=k;i++) if(l[j].first<=t[a[j]]) l[i].second=0;
				r=t[a[j]];
				memset(t,0,sizeof(t));
				k=0;
			}
			k++;
			t[a[j]]=j,l[k].second=a[j],l[k].first=j;
		}
		for(int j=1;j<=k;j++) mt[l[j].second]++;
	}
	for(int i=1;i<=m;i++) cout<<mt[i]<<" ";
	return 0;
} 
