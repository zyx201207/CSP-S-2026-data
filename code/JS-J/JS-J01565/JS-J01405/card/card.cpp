#include<bits/stdc++.h>
using namespace std;
long long n,m,c;
long long a[500005],lastdis[300005],q[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int tmp=1;
	while(tmp!=n){
		c=1;
		memset(lastdis,0,sizeof(lastdis));
		for(int i=tmp;i<=n;i++){
			if(lastdis[a[i]]==0){
				lastdis[a[i]]=c;
				q[c]=a[i];
				c++;
			}else{
				for(int j=lastdis[a[i]]+1;j<c;j++)
					lastdis[q[j]]=0;
				c=lastdis[a[i]];
				c++;
			}
		}
		for(int i=1;i<c;i++)
			ans[q[i]]++;
		tmp++;
	}
	ans[a[n]]++;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
