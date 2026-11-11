#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,cnt;
string s,a1,a2;
int f(int l)
{
	if(l%2){
		return l/2+2;
	}
	else{
		return l/2+1;
	}
} 
int main()
{
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y; 
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int l=s.size();
	int ni=f(l);
	for(int i=1;i<=l/2;i++){
		a1+=s[i-1];
	}
	for(int i=ni;i<=l;i++){
		a2+=s[i-1];
	}
	for(int i=1;i<=l/2;i++){
		if(a1[i-1]!=a2[i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
