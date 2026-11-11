#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int x;
	char c;
	string s;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&x,&c);
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	long long len=s.length();
	long long cnt=0;
	for(int i=0;i<=(len-1)/2;i++){
		if(s[i]!=s[len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}