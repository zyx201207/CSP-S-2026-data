#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int a;char c;
		cin>>a>>c;
		while(a--)s1+=c;
	}
	int ans=0;	
	for(int i=0,j=s1.size()-1;i!=j;++i,--j){
		if(s1[i]!=s1[j])ans++;
	}cout<<ans;
	return 0;
}
