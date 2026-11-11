#include<bits/stdc++.h>
using namespace std;
string s;
map<int,char>mp;
int n;
long long len,ans;
int x[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long x;
		char c;
		cin>>x>>c;
		while(x--)s+=c,l++;
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
			//cout<<i<<"\n";
		}
	}
	//60pts
	cout<<ans;
	return 0;
}
