#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	int n,len=0;
	cin>>n;
	while(n--){
		int a;char c;
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++) s+=c;
	}
	string ss;
	for(int i=0;i<len;i++)
		ss+=s[len-i-1];
	int cnt=0;
	for(int i=0;i<len;i++)
		if(s[i]==ss[i]) cnt++;
	cout<<(len-cnt)/2;
	return 0;
}//68
