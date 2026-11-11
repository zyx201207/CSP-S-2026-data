#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	string ans="";
	for(int i=1;i<=n;++i){
		for(int j=1;j<=a[i];++j){
			ans+=c[i];
		}
	}
	string s=ans;
	reverse(ans.begin(),ans.end());
	if(s==ans){
		cout<<0;
		return 0; 
	}
	int lens=ans.size();
	int cnt=0;
	for(int i=0;i<lens/2;++i){
		for(int j=lens-1;j>i;j--){
			if(ans[i]!=ans[j])cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
