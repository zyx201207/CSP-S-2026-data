#include<bits/stdc++.h>
using namespace std;
	string s,r;
	char c;
	long long int n,a,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>a>>c;
		for(long long int j=1;j<=a;j++){
			s+=c;
			r=c+r;
		}
	}
	int len=s.size();
	for(long long int i=0;i<=len-1;i++){
		if(s[i]!=r[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
}

