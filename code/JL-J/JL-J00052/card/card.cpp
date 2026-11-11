#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m+1],ss[n+1],ans[m+1],dqs=0;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)cin>>ss[i];
	for(int i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		for(int j=i;j<=n;j++){
			if(a[ss[j]]!=0){
				for(int k=1;k<=m;k++){
					if(a[k]>a[ss[j]]){
						a[k]=0;
						dqs--;
					}
				}
			}else{
				dqs++;
				a[ss[j]]=dqs;
			}
		}
		for(int j=1;j<=m;j++)if(a[j]!=0)ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
}

