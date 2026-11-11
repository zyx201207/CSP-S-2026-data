#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
int flag[M],pd[N];//上一个，是否删去 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		memset(pd,0,sizeof pd);
		for(int j=i;j<=n;j++){
			if(flag[a[j]]){
				for(int k=flag[a[j]];k<j;k++){
					if(!pd[k]){
						pd[k]=true;
						ans[a[k]]--;
					}
				}
			}
			flag[a[j]]=j;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
