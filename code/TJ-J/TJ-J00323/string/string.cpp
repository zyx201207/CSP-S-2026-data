#include <bits/stdc++.h>
using namespace std;
vector<char> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b=0;
		char c;
		cin>>a>>c;
		for(int i=b;i<a+b;i++){
			s.push_back(c);
		}
		b+=a;
	}
	int f,m=0;
	f=s.size();
	for(int i=0;i<f/2;i++){
		int l,r;
		l=i;
		r=f-i-1;
		if(s[l]!=s[r]){
			s[r]=s[l];
			m++;
		}
	}
	cout<<m;
	return 0;
}
