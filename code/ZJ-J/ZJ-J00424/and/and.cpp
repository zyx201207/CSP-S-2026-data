#include<bits/stdc++.h>
using namespace std;
//你的freopen去掉注释了吗（估计0分）
/*
吾日三省吾身：
freopen去掉注释了吗？
关闭输入输出流了吗？
编译选项开O2优化了吗

*/
int n,m,a[200005],dp[200005],ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(a[i]==a[j])ans=max(ans,a[i]);
		}
	}
	cout<<ans;
	 
	return 0;
}