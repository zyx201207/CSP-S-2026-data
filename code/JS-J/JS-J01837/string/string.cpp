#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200005];
char c[200005];//48pts
ll m=0;
string s="";
int cnt=0;
int fun(int l,int r){
//	cout<<l<<" "<<r<<endl;
	cnt++;
	if(l==r){
		return 0;
	}
	if(r-l==1){
		if(s[l]==s[r])return 0;
		else return 1;
	}
	if(s[l]==s[r])return fun(l+1,r-1);
	return 1+fun(l+1,r-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int ma=INT_MIN;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	for(int j=0;j<a[i];j++){
		s+=c[i];
	}
	ma=max(ma,a[i]);
}
	int m=s.size();
	cout<<fun(0,m-1);
	return 0;
}//CSP 2026 RP++
/*
3
2 a
2 b
1 c
*/
