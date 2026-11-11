//08:55 开题！ 
//08:56 这啥玩意儿。是 T2 吗。 
//09:01 完了 wzq (My friend,uid=1239752) 的话真的应验了，T2 我不会做 
//09:22 换个思路，先看看暴力 
//09:34 我受不了了，看能不能把 56pts 骗到，然后先看 T3
//		Oh, T2 setter, this problem is too hard (or there is water full of my brain). Don't set T2 like this again.
//09:39 I got only 56pts.OHHHHHHHHHH MY 1= !
//11:05 我回来了，1= 悬，看能不能过掉这题 
//11:28 什么阴间玩意儿，半天没想到解法
//		How CSP-J T2? 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct Char{
	int a;
	char c;
}s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].c;
	if(n==1){//task 1 4pts
		cout<<0;
		return 0;
	}
	if(n==2){//task 2-4 12pts
		if(s[1].c==s[2].c)cout<<0;
		else cout<<min(s[1].a,s[2].a);
		return 0;
	}
	//task 5-12,17,18 40pts
		int ans=0;
		string l="";
		for(int i=1;i<=n;i++)
			for(int j=1;j<=s[i].a;j++)
				l+=s[i].c;
		int sz=l.size();
		for(int i=0;;i++){
			int j=sz-i-1;
			if(i>j)break;
			if(l[i]!=l[j])
				ans++;
		}
		cout<<ans;
	return 0;
} 
//本题分数 56pts 
