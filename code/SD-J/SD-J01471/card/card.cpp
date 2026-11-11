#include <bits/stdc++.h>
using namespace std;
int n,m,a[500011],zhuo[500011],l = 0,ans[300011];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		memset(zhuo,0,sizeof(zhuo));
		l = 0;
		for(int j = i;j <= n;j++){
			if(j == i){
				zhuo[++l] = a[j];
				continue;
			}
			int id = 0;
			bool u = true;
			for(int k = 1;k <= l;k++)
				if(zhuo[k] == a[j]){
					id = k;
					u = false;
					break;
				}
			if(!u){
				for(int k = id + 1;k <= l;k++)
					zhuo[k] = 0;
				zhuo[id + 1] = a[j];
				l = id + 1;
				continue;
			}
			zhuo[++l] = a[j];
		}
		bool u1[300011];
		memset(u1,true,sizeof(u1));
		for(int j = 1;j <= l;j++){
			if(u1[zhuo[j]])
				ans[zhuo[j]]++,u1[zhuo[j]] = false;
		}
	}
	for(int i = 1;i <= m;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
