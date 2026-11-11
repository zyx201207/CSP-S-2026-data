#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=30;i>=0;--i){
		int sum=0;
		for(int j=1;j<=n;++j){
			if(!vis[j]&&(a[j]>>i&1))++sum;
		}
		if(sum>=m){
			ans+=1<<i;
			for(int j=1;j<=n;++j)
				if(!a[j]>>i&1)vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
//ya suo bao mi ma:Trick||Treat!
//you ji:
//zhu yi dao mei you zhong wen shu ru fa
//8:48 T1test AC
//8:53 kai T2
//9:30 T2test AC
//9:38 kai T3
//9:56 T3test AC(chu le test6 wei ce)
//10:00 Dev-C++ ka zhu
//10:01 chong xie T3 code
//10:06 T3test AC