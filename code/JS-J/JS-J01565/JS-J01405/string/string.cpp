#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m[200005],cnt,maxi;
char c[200005];
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
		if(i==1) maxi=m[1];
		else maxi=gcd(maxi,m[i]);
	}
	for(int i=1;i<=n;i++){
		int tmp=m[i]/maxi;
		while(tmp--)
			s=s+c[i];
	}
	int p=0,q=s.length()-1;
	while(p<q){
		if(s[p]!=s[q]) cnt++;
		p++,q--;
	}
	cout<<cnt*maxi;
	return 0;
}
