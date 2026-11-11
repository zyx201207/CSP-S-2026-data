#define ll long long

#include<bits/stdc++.h>
using namespace std;
const int mx = 5e5 + 10;
int a[mx];
int ans[mx];
int f[mx];
int q[mx],t = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		memset(f,0,sizeof(f));
		t = 0;
		for(int j = i;j <= n;j++){
			if(f[a[j]] == 0 || f[a[j]] > t || q[f[a[j]]] != a[j]){
				q[++t] = a[j];
				f[a[j]] = t;
			}else{
				t = f[a[j]];
			}
		}
		for(int j = 1;j <= t;j++)ans[q[j]]++;
	}
	for(int i = 1;i <= m;i++)printf("%d ",ans[i]);
	return 0;
}
