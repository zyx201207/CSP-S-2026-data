#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],num[500010],ans[500010];
int main(){
	cin.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		memset(num,0,sizeof(num));
		int cnt=0;
		for(int i=k;i<=n;i++){
			int f=0;
			for(int j=1;j<=cnt;j++){
				if(num[j]==a[i]){
					f=j;
					break;
				}
			}
			if(f==0)num[++cnt]=a[i];
			else{
				for(int j=f;j<=cnt;j++)num[j]=0;
				num[f]=a[i];
				cnt=f;
			}
		}
		for(int i=1;i<=cnt;i++){
			ans[num[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
