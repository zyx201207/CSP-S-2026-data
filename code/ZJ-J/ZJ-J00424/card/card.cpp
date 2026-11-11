#include<bits/stdc++.h>
using namespace std;
//#error 你的freopen去掉注释了吗（目标：暴力48分）已达成
/*
吾日三省吾身：
freopen去掉注释了吗？
关闭输入输出流了吗？
编译选项开O2优化了吗

*/
int n,m,a[500005],q[300005],hh,ans[300005];
void solve(int x){
	for(int i=x;i<=n;i++){
		for(int j=1;j<=hh;j++){
			if(q[j]==a[i]){
				hh=j-1;
				break;
			}
		}
		q[++hh]=a[i];
	}
	for(int i=1;i<=hh;i++){
		ans[q[i]]++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		hh=0;
		solve(i);
	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}