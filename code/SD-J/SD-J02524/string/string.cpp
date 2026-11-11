#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,sum,x;
string s,ss,y;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=0;i<x;i++){
			s+=y;
		}
	}
	for(int i=0;i<s.size();i++){
		ss[s.size()-i-1]=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=ss[i]) sum++;
	}
	cout<<sum/2;
	return 0;
}
