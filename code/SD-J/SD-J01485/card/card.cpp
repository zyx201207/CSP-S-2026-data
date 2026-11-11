#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int x=n;
	int y=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(n--){
		int b[x],idd[m],f[m];
		memset(b,0,sizeof b);
		memset(idd,0,sizeof idd);
		memset(f,0,sizeof f);
		for(int i=y;i<=x;i++){
			b[i]=a[i];
			if(f[a[i]]==0) idd[a[i]]=i;
			else{
				for(int j=idd[a[i]];j<i;j++){
					b[j]=0;
					f[a[j]]=0;
					idd[a[j]]=0;
				}
				idd[a[i]]=i;
			}
			f[a[i]]=1;
		}
		for(int i=y;i<=x;i++){
			ans[b[i]]++;
		}
		y++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
