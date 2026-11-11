#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],k,ans[500005];
int find(int x,int id){
	int s=0;
	for(int i=1;i<=id;i++){
		if(b[i]==x) s=i;
	}
	return s;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		k=0;
		for(int j=i;j<=n;j++){
			int x=find(a[j],j-1);
			if(x==0) b[++k]=a[j];
			else{
//				kill (x-(j-1))
				for(int l=x;l<j;l++)
					b[l]=b[l+(j-x)];
				k=x-1;
				b[++k]=a[j];
			}
		}
		for(int i=1;i<=k;i++) ans[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}