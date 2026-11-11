#include<bits/stdc++.h>
using namespace std;
string s1;
char c;
long long a,n,ans;
string ss,sss;
int qiucha(long long x,string s){
	int y=x/2;
	if(x%2==0){
		for(long long i=0;i<=y-1;i++) ss+=s[i];
		for(long long i=x-1;i>=y;i--) sss+=s[i];
	}else{
		for(long long i=0;i<=y;i++) ss+=s[i];
		for(long long i=x-1;i>=y;i--) sss+=s[i];
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long xx=0;
	while(n--){
		cin>>a>>c;
		for(long long i=1;i<=a;i++) s1+=c;
		xx+=a;
	}
	qiucha(xx,s1);
	for(long long i=0;i<=xx/2;i++){
		if(ss[i]!=sss[i]) ans++;
	}
	cout<<ans;
	return 0;
}
