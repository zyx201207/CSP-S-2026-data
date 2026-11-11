#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int l[N];
char w[N];
string s="";
long long ans=0;
long long len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>w[i];
		len+=l[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i];j++)
			s+=w[i];
	}
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
