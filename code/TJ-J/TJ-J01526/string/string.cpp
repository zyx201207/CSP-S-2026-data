#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)s+=c;
	}
	int i=0,j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j])ans++;
		i++,j--;
	}
	cout<<ans;
	return 0;
} 
