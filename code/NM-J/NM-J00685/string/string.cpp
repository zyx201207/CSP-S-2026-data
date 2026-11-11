#include<bits/stdc++.h>
using namespace std;
string s,a;
int l,r,n,m,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m>>a;
		for(int i=1;i<=m;i++){
			s+=a;
		}
	}
//	cout<<s;
	l=0;r=s.size();
	while(l<r){
		if(s[l]!=s[r]) {
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
//qu xiao zhu shi
}
