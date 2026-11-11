#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k,cnt=-1,sum=0;
	char x;
	string s,t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>x;
		for(int j=1;j<=k;j++){
			cnt++;
			s[cnt]=x;
		}
	}
	cnt++;
	for(int i=0;i<cnt;i++){
		t[i]=s[cnt-i-1];
	}
	for(int i=0;i<=cnt/2;i++){
		if(t[i]!=s[i]) sum++;
	}
	cout<<sum;
	return 0;
} 
