#include<bits/stdc++.h>
using namespace std;
long long int n,x,cnt;
string s,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>y;
		while(x--) s+=y;
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
