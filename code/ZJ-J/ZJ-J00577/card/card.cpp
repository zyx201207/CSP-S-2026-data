#include <bits/stdc++.h>
#define ll long long
using namespace std;
//此题考虑骗分
//对于n<=5000样例可以n*n做法
//遍历每局游戏 
//对于每个数，找到第一个出现的与最后一个出现的
//在第一个出现的地方时将中间的数字都跳过 
int a[500010];
ll c[300010]; 
ll s[300010];
ll e[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int i=1;i<=m;i++){
				s[i]=1e18;
				e[i]=-1;
			}
			for(ll j=i;j<=n;j++){
				s[a[j]]=min(s[a[j]],j);
				e[a[j]]=max(e[a[j]],j);
			}
			int l=i;
			c[a[i]]++;
			while(l<=n){
				if(l==s[a[l]]&&e[a[l]]!=-1){
					l=e[a[l]];
				}
				l++;
				c[a[l]]++;
			}
		} 
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
		return 0;
	} //48pts
	return 0;
}
//好心人可以送我400pts吗？ 
