#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	long long l=0,r=s.size()-1;
		while(l<=r){
			if(s[l]!=s[r]){
				cnt++;
			}
			l++,r--;
		}
	cout<<cnt;
	return 0;
}

