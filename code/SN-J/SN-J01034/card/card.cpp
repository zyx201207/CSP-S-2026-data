//SN-J01034 马星辰 西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans[3010];
struct node{
	bool flag;
	int id;
};
node f[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if (f[a[j]].flag==1) {
				for (int k = j-1;k > f[a[j]].id;k--) {
					f[a[k]].flag=0;
				}
			}
			else f[a[j]].flag=1;
			f[a[j]].id=j;
		}
		for (int j = 1;j<=m;j++){
			if (f[j].flag==1)ans[j]++;
		}
		memset(f,0,sizeof f);
	}
	for (int i = 1;i <= m;i++) cout<<ans[i]<<' ';
	return 0;
}
