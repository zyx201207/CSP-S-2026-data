#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt=0;
string s;
char c;
int main(){
	freopen("in.string","r",stdin);
	freopen("out.string","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%d%s",&a,&c);
		while(a){
			s.push_back(c);
			a--;
		}
	}
	n=s.size();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]){
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}
