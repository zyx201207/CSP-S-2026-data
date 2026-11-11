#include<bits/stdc++.h>
using namespace std;long long n,x,cnt;char c;string s,s0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	s0=s;
	reverse(s0.begin(),s0.end());
	for(int i=1;i<=s.size()/2+(s.size()%2?1:0);i++){
		if(s[i]!=s0[i]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
