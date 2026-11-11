#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
string c;
string s,sa;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c;
		for(int j=0;j<a[i];j++){
			s=s+c;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		sa=sa+s[i];
	}
	for(int i=0;i<s.size();i++){
		if(sa[i]!=s[i]){
			sa[i]=s[i];
			s[s.size()-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
}