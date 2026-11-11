#include<bits/stdc++.h>
using namespace std;
int n;
string a;
long long l=1,cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		char tt;
		long long t;
		cin>>t>>tt;
		for(int j=l;j<l+t;++j){
			a[j]=tt;
		}l+=t;
	}l--;
	for(int i=1;i<=l/2;++i){
		if(a[i]!=a[l-i+1]) cnt++;
	}cout<<cnt;
	return 0;
}
