#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
char s;
string w="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a,&s);
		for(int i=1;i<=a;i++) w+=s;
	}
	for(int i=0,j=w.size()-1;i<w.size()/2;i++,j--){
		if(w[i]!=w[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}
