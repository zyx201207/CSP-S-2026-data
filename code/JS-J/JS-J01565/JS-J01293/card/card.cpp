#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100300],zhuangtai[100300],weizhi[100300],sum[100300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			zhuangtai[i]=0;
		}
		long long cnt=1;
		for(int j=i;j<=n;j++){
			if(zhuangtai[a[j]]==0){
				zhuangtai[a[j]]=1;
				weizhi[cnt]=a[j];
				cnt++;
			}
			else{
				for(int x=1;x<=cnt;x++){
					if(weizhi[x]==a[j]){
						for(int y=x;y<=cnt;y++){
							zhuangtai[weizhi[y]]=0;
						}
					}
				}
				weizhi[cnt]=a[j];
				cnt++;
			}
		}
		for(int i=1;i<=m;i++){
			if(zhuangtai[i]==1){
				sum[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
