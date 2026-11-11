#include<bits/stdc++.h>
using namespace std;
long long m;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string x;
	for(int i=1;i<=n;i++){
		cin>>m>>s;
		for(int i=1;i<=m;i++){
			x+=s;
		}
	}
	int d=x.size();
	long long cnt=0;
	for(int i=0;i<d/2;i++){
		if(x[i]!=x[d-i-1]) cnt++;
	}
	cout<<cnt;
}  
