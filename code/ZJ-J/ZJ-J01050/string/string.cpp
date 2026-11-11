#include<bits/stdc++.h>
using namespace std;
char s[200010];
int l,i,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	while(n--){
		int x; char c; cin>>x>>c;
		for(int t=0;t<x;t++){
			s[++i] = c;
		}
		l += x;
	}
	for(int i=1;i<=ceil(l/2);i++){
		if(s[i]!=s[l-i+1]) cnt ++;
	}
	cout<<cnt;
	return 0;
}