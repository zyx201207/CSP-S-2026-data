#include <bits/stdc++.h>
using namespace std;
long long n,x=0,min1,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	min1=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[x]=b;
			x++;
		}
	}
	int len=s.size();
	if(s[0]!=s[len-1]){
		cnt++;
	}
	for(int i=0;i<=len-1;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}