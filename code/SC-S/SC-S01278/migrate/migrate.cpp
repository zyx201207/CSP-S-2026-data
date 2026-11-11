#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5;
int n,C,T;
ll m,a[N];
int pos[N],kt[N],rf;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n>=5e4){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			pos[i]=pos[i-1];
			while(pos[i]+1<=n && a[pos[i]+1]<=a[i]+m) pos[i]++;
		}
		rf=0;
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]>m) kt[++rf]=i-1;
		ll ans=0; int it=1;
		kt[++rf]=n;
		for(int l=1;l<=n;l++){
			while(l>kt[it] && it<rf) it++;
			for(int r=l+1;r<=kt[it];r++){
//				cout<<r<<' '<<kt[it]<<'\n';
				int u=0;
				for(int i=l;i<r;i=pos[i]){
					if(pos[i]==i){ u=0; break; }
					int j=1;
					while(i-j>=l && (pos[i]==pos[i-j] || (pos[i]>=r && pos[i-j]>=r)) && j<3) u++,j++;
					if(u>1) break;
				}
				if(u==1) ans++; 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
这个双径岛屿对肯定是有什么神秘小性质的
如果在两个岛之间有且只有两条路径，那必然有性质
1. 两条路径中必然有一次跳跃没有跳到自己最大能跳的地方
2. 直接按照最大的去跳，跳到最后一定是最优方案的一种（最多有一次没有最大）
3. pos 相同的点对在双径岛屿中只能有一个，点群直接坠机
相当于把问题转化成找只包含一个 pos 相同的点对的区间个数
这肯定也需要神秘性质，直接上结构体好像不行
寻找性质失败 大大坠机
直接n^3暴力
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

