#include <bits/stdc++.h>
using namespace std;
long long n,a,cnt=0,t=1;
char c;
string s;
bool flag=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[t]=c;
			t++;
		}
	}
	for(int l=1;l<=s.size();l++){
		for(int r=s.size();r>=1;r--){
			if(s[r]!=s[l]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}