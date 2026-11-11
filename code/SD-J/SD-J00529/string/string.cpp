#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e5+5;
struct node{
	int len;
	char c;
}a[N];
string s="";
bool f1,f2;
void solve1(){//O(N^2) 32~48·Ö 
	int cnt=0,len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].len;j++){
			s+=a[i].c;
		}
		len+=a[i].len;
	}
	int i=0,j=len-1;
	while(i<=j){
		if(s[i]!=s[j]) cnt++;
		i++,j--;
	}
	cout<<cnt;
}
void solve2(){//O(N) 4~12·Ö 
	int cnt=0;
	for(int i=1;i<=n;i++){
		s+=a[i].c;
	}
	int i=0,j=n-1;
	while(i<j){
		if(s[i]!=s[j]) cnt++;
		i++,j--;
	}
	cout<<cnt*a[1].len*1ll;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		if(i>1){
			if(a[i].c!=a[i-1].c) f1=1;
			if(a[i].len!=a[i-1].len) f2=1;
		}
	}
	if(f1==0){//O(1) 4~12·Ö 
		cout<<0;
		return 0;
	}
	if(f2==0) solve2();
	else solve1();
	return 0;
}
