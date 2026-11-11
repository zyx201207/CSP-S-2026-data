#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500005],b[500005],tot=1,ans[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<long long,long long> c;
		tot=0;
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(c[a[j]]>1){
				while(1==1){
					if(b[tot]==a[j]){
						break;
					}
					c[a[tot]]--;
					tot--;
				}
				c[a[j]]=1;
			}else{
				tot++;
				b[tot]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=c[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0; 
} 
