#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int flag[300005];
int a1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		memset(a1,0,sizeof(a1));
		int cnt=0;
		for(int i=k;i<=n;i++){
		
			if(cnt==0){
				cnt++;
				a1[cnt]=a[i];
			}else{
				int flag1=0;
				for(int j=1;j<=cnt;j++){
					if(a[i]==a1[j]){
						flag1=j;
						break;
					}
				}
				if(flag1==0){
					cnt++;
					a1[cnt]=a[i];
				}else{
					for(int j=flag1;j<=cnt;j++){
						a1[j]=0;
					}
					cnt=flag1;
					a1[cnt]=a[i];
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			flag[a1[i]]++;
		}
	}
	for(int k=1;k<=m;k++){
		cout<<flag[k]<<" ";
	}
	return 0;
}