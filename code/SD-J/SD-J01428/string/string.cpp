#include<iostream>
#include<cstdio>
using namespace std;
int n,q,len,minn=1e9;
string s=" ";
char c;
bool chick(){
	for (int i=1,j=len;i<=j;i++,j--){
		if (s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}
void dfs(int dep,int cs){
	if (chick()){
	    minn=min(cs,minn);
		return ;
	}
	for (int i=0;i<=25;i++){
		s[dep]='a'+i;
		dfs(dep+1,cs+1);
		return ;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%s",&q,&c);
		len+=q;
		for (int i=1;i<=q;i++){
			s+=c;
		}
	}
	if (n==1){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<minn/2;
	return 0;
}
