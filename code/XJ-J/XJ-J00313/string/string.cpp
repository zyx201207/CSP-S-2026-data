#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0,n,a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		for(int j=len-1;j>=0;j--){
			if(s[j]!=s[i]){
				ans++;
				continue;
			}
		}
	}
	cout<<ans/8;
	return 0;
}