#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5; 
string s;
int n,x;
char y;
int q;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		while(x--){
			s+=y;
		} 
	}
	n=s.size();
	for(int i=0;i<=(n+1)/2-1;i++){
		if(s[i]!=s[n-1-i]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
