#include<bits/stdc++.h>
using namespace std;
long long n,a,len;
char c;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long t=0;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--){
			s[t]=c; 
		}
		t+=a;
		len+=a;
	}
	long long cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-1-i]){
			s[len-1-i]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
}
