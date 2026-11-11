#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int cnt[1000005];
string s;
bool f=1;
char b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>b[i];
		int x=cnt[i];
		for(int j=1;j<=x;j++){
			s+=b[i];
		}
	}
	for(int i=1;i<n;i++){
		if(b[i]!=b[i+1]) f=0;
	}
	if(f){
		cout<<0<<endl;
		return 0;
	}
	int l=0,r=s.size();
	while(l<=r){
		if(s[l]!=s[r])
			 ans++;
		l++;r--;
	}
	cout<<ans<<endl;
	return 0;
}
