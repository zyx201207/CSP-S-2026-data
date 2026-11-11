#include <bits/stdc++.h>
using namespace std ;
unsigned long long sum ;
long long n,a[200005];
char c[200005] ;
map <char,long long> mp,mp1 ;
long long mx = 0 ;
string s ;
void f1(){
	int a1 = sum % 2 ;
	if(mx>=sum/2+a1){
		cout<<sum-mx;
		return ;
	}
	else{
		cout<<mx;
		return ;
	}
}
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mp1[c[i]] ++ ;
		mp[c[i]] += a[i] ;
		sum += a[i] ;
	}
	long long cnt = 0;
	for(auto c:mp1){
		if(c.second>0) cnt++ ;
		
	}
	for(auto c:mp){
		mx = max(mx,c.second) ;
	}
	if(cnt==1){
		cout<<0<<"\n";
		return 0 ;
	}
	f1() ;
	return 0 ;
} 
