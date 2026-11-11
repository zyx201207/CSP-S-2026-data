#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s1;
		for(int j=1;j<=m;j++){
			s+=s1;
		}
	}
	int len=s.size();
	int l=0,r=len-1;
	int ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			ans++;
			l++;
			r--;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}