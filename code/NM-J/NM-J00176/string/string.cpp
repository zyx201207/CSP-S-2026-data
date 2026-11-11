#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,ans;
vector<char>str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		LL a;
		char c;
		cin>>a>>c;
		while(a--)str.push_back(c);
	}
	for(int i=0,j=str.size()-1;i<=str.size()/2;i++,j--){
		if(str[i]!=str[j])ans++;
	}
	cout<<ans;
	return 0;
}
