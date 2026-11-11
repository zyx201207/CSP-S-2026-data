//SN-J00767 汤佳忆 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int a;
	char c;
}s[N];
int l;
string ss; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i].a>>s[i].c;
		l+=s[i].a;
		ss+=s[i].c;
	}
	int ans=0,mid=l/2;
	for(int i=0;i<=mid;++i){
		if(ss[i]!=ss[l+1-i])ans++;
	}
	cout<<ans;
	return 0;
} 
