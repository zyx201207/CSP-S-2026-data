#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long k=0;
long long len[200005];
char c[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++){
			s+=c[i];
		}
	}
	long long t=s.size();
	for(int i=1;i<=t/2;i++){
		if(s[i-1]!=s[t-i]){
			k++;
		}
	}
	cout<<k;
	return 0;
}
