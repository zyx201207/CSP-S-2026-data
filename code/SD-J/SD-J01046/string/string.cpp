#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int x;char y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
	long long len=s.size();
	for(long long i=0,j=len-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0; 
}
