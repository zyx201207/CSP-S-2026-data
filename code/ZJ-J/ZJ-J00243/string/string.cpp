#include <bits/stdc++.h>
using namespace std;

int n;
int lll,rrr;
long long a[200008];
long long lft=1;
long long rgt;
char l,r;
long long ll,rr;
string s;
void func(){
	if(ll==a[lll]+1){
		ll=1;
		l=s[lll];
		lll++; 
	}
	if(rr==0){
		rr=a[rrr-1];
		r=s[rrr-1];
		rrr--;
	}
}
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	lll=1;
	rrr=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
		rgt+=a[i];
	}long long sum=0;
	ll=a[1];
	rr=a[n];
	l=s[1];
	r=s[n];
	while(lft<rgt-1){
		func();
		if(l!=r)sum++;
		lft++;
		rgt--;
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
