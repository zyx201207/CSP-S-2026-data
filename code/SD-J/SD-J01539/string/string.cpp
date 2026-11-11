#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int w[N];
int x;
char c[N];
string s;
int ans;
int cnt;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w[i]>>c[i];
		for(int j=0;j<w[i];j++){
			s+=c[i];
		}
	}
	int sum=s.size();
	for(int i=0;i<s.size();i++){
		a+=s[i];
	}
	if(a[0]!=a[sum]){
		ans++;
	}
	for(int i=0;i<s.size();i++){
		sum--;
		if(a[i]!=a[sum]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
} 
/*
3
2 a
2 b
1 c
*/
