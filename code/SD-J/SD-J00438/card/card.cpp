#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5+10;
const int maxm = 3e5+10;

int n, m;

int a[maxn];
int f[maxm];//点数为i的卡牌出现次数 
int p[maxm];//记录此堆里最左边出现的点数为I的拍的位置 
int c[maxn], cnt = 0;//当前卡牌堆 
int ans[maxm];//最后的 

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];	
	}
	for(int i = 1;i <= n;i++){//从第i张卡牌开始发 
		for(int j = 1;j <= m;j++)f[j] = 0;
		for(int j = 1;j <= n;j++)c[j] = 0;
		for(int j = 1;j <= m;j++)p[j] = 0;//初始化（memset为什么用不了啊） 
		
		for(int j = i;j <= n;j++){
			if(f[a[j]] == 0){
				c[++cnt] = a[j];
				p[a[j]] = cnt;
				f[a[j]]++;
			}else{
				for(int k = cnt;k > p[a[j]];k--){
					f[c[k]]--;
					if(p[c[k]] == k) p[c[k]] = 0;
				}
				cnt = p[a[j]];
			}
		}
		for(int j = 1;j <= m;j++){
			ans[j] += f[j];
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " "; 
	}
	return 0;
}
