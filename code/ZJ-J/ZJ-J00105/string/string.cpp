#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
string res,s;
struct node{
	LL a;
	string c;
};
node b[200005];
LL hh(){
	LL cnt=0;
	LL len=(LL)s.size();
	for(LL i=0;i<len/2ll;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
	} 
	for(LL i=1;i<=n/2;i++){
		if(b[i].c==b[n-i+1].c){
			LL p=min(b[i].a,b[n-i+1].a);
			b[i].a-=p;
			b[n-i+1].a-=p;
		}
	}
	for(LL i=1;i<=n;i++){
		if(b[i].a>=10000){
			string t="";
			LL cnt=b[i].a/100000;
			LL ans=b[i].a%100000;
			for(LL j=1;j<=100000;j++){
				t+=b[i].c;
			}
			for(LL j=1;j<=cnt;j++){
				s+=t;
			}
			for(LL j=1;j<=ans;j++){
				s+=b[i].c;
			}
		}
		else{
			for(LL j=1;j<=b[i].a;j++){
				s+=b[i].c;
			}
		}
	}
	cout<<hh();
	return 0;
} 
