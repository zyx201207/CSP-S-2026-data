#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l[500005],ans[300005];
bool f[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k=1;
		//模拟每局 
		for(int j=1;j<=m;j++) f[j]=0;
		for(int j=i;j<=n;j++){
			//当前牌若在桌面上已存在 
			if(f[a[j]]!=0){
				//枚举寻找 
				for(int x=k-1;x>=1;x--){
					if(l[x]==a[j]){
						k=x;
						break;
					}
					f[l[x]]=0;
					ans[l[x]]--;
				}
			}
			//不存在就直接下一步 
			else{
				f[a[j]]=1;
				ans[a[j]]++;
				l[k]=a[j];
			}
			k++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//一眨眼，时间过隙 ，我竟然已五次参加CSP，时间好快，好快。前途渺茫啊，唉＞︿＜ 
