#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		string e;
		cin>>x>>e;
		for(long long j=1;j<=x;j++){
			s=s+e;
		}
	}
	long long le=0,ri=s.size()-1;
	while(le<=ri){
		if(s[le]!=s[ri]) cnt++;
		le++,ri--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
