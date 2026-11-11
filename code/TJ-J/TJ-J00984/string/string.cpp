#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",strout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>c;
		for(long long j=0;j<m;j++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			x++;
		}
	}
	cout<<x;
	return 0;
}
