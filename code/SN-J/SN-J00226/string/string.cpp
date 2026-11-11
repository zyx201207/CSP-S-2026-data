#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		while(x--)s+=c;
	}
	cout<<s<<'\n';
	for(int i=1,j=s.size();i<=j;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
	return 0;
}
