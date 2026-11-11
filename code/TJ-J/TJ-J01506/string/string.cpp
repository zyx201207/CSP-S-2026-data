#include<bits/stdc++.h>
using namespace std;
int n;
string s,s1;
int a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		ans+=a;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=ans-1;i>=0;i--){
		s1+=s[i];
	}
	long long cnt=0;
	for(int i=ans/2;i<ans;i++){
		if(s1[i]!=s[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
