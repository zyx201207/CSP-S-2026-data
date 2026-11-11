#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 _i;
const int N=1e9;
int a[200015];
char c[200015];
stack<int> st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ull ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<"0";
			return 0;
		}
		string s="";
		for(int i=1;i<=n;i++){
			s+=c[i];
		}
		if(a[1]>a[2]){
			cout<<a[1];
			return 0;
		}else if(a[1]<a[2]){
			cout<<a[2];
			return 0;
		}else{
			cout<<a[1];
			return 0;
		}
	}
	return 0;
}
