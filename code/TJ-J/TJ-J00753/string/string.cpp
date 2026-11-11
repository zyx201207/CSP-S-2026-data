#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0,b=0,t=0;
char s[100005],c;
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		t+=a;
		for(b;b<t;b++){
			s[b]=c;
		}
	}
	b--;
	for(int i=0;i<t-1;i++){
		if(s[i]!=s[b]){
			s[b]=s[i];
			ans++;
		}
		b--;
	}
	cout<<ans;
	return 0;
} 
