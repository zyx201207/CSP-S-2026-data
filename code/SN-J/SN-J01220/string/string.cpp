#include <bits/stdc++.h> 
using namespace std;
string s;
char a[100005];
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	string s;
	long long n,m[100005],ans=0;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>m[i];
		cin>>a[i];
		for(int j=1;j<=m[i];j++){
			s+=a[i];}
	}
	for(int i=s.size();i>s.size()/2+1;i--){
		int q=0;
		if(s[q]!=s[i-1]){
			++ans;
		}
		++q;
	}
	cout<<ans;
	return 0;
}
