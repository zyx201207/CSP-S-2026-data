#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s[1000000005];
	char c;
	int a,n;
	cin>>n;
	int L=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for (int j=0;j<a;j++){
			s[j]=c;
		}
		L+=a;
	}
	int cnt=0;
	for(int i=1;i<=L;i++){
		if(s[L+1-i]!=s[i])
			s[L+1-i]=s[i];
			cnt++;
		}
	cout<<cnt;
	return 0;
}