#include<bits/stdc++.h>
using namespace std;
string s;
char a;
int n,k;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>a;
		while(k--){
			s+=a;	
		}
	}
	for(int i=0;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
