#include<bits/stdc++.h>
using namespace std;
int n,m,h[300005],kill[500005],ans[300005],k[300005];
struct point{
	int num,l,r;
};
point a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i].num);
		a[i].l = h[a[i].num];
		a[h[a[i].num]].r = i;
		h[a[i].num] = i;
	}
	for(int i = 1;i<=n;i++){
		if(i == h[a[i].num])continue;
		kill[i]+1,kill[a[i].r]-1;
	}
	for(int i = 1;i<=n;i++){
		kill[i] += kill[i-1];
		if(kill[i] == 0)ans[a[i].num] = i,k[a[i].num] = i;
	}
	for(int i = 1;i<n;i++){
		if(h[a[i].num] == i)continue;
		for(int j = i;j<=a[i].r;j++){
			kill[j]--;
			if(kill[j] == 0){
				if(k[a[j].num] < i+1)ans[a[j].num] += j+1-i,k[a[j].num] = j;
				else ans[a[j].num] += j-k[a[j].num],k[a[j].num] = j;
			}
		}
	}
	for(int i = 1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}