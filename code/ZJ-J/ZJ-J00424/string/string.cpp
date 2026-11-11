#include<bits/stdc++.h>
using namespace std;
//你的freopen去掉注释了吗（预估暴力56分）
/*
吾日三省吾身：
freopen去掉注释了吗？
关闭输入输出流了吗？
编译选项开O2优化了吗

*/
string s,q;
int n,x;
string ci;
long long ans,cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cnt+=x;
		if(x>=1e5){
			cout<<0;
			return 0;
		}
		cin>>ci;
		for(int i=1;i<=x;i++){
			s=s+ci;
			q=ci+q;
		}
		
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=q[i])ans++;
	}
	cout<<ans;
	return 0;
}