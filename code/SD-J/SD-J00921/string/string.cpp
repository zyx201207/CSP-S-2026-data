#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	bool b=1;
	int ans=0;
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			ans++;
			b=0;
		}
	}
	if(b==1){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
