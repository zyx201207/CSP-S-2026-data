#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
int a;
char c;
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	//cout<<s;
	int L=0,R=s.size()-1;
	while(L<=R){
		if(s[L]!=s[R]){
			cnt++;
			//cout<<L<<" "<<R<<endl;
		}
		L++;
		R--;
	}
	cout<<cnt;
	return 0;
}
