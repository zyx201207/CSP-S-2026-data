#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans[1000005],cur[1000005],d[1000005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(cur,0,sizeof(cur));
		memset(d,0,sizeof(d));
		cnt=0;
		for(int j=i;j<=n;j++){
			if(d[a[j]]==0)cur[++cnt]=a[j],d[a[j]]=cnt;
			else{
				cnt=d[a[j]];
				cur[cnt]=a[j];
				d[a[j]]=cnt;
			}
		}
		for(int i=1;i<=cnt;i++){
			ans[cur[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
