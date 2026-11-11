#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum;
string s,x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		char c;
		cin>>a[i]>>c;
		while(a[i]--){
			s+=c;
		}
	}
	int f;
	if((s.size()-1)%2==0){
		f=(s.size()-1)/2;		
	}
	else{
		f=s.size()/2;
	}
	for(int i=0;i<f;++i){
		x+=s[i];
	}
	for(int i=s.size()-1;i>=s.size()-f;--i){
		y+=s[i];
	}
	int cnt=0;
	for(int i=0;i<x.size();++i){
		if(x[i]!=y[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
