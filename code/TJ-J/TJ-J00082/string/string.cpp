#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
void add(long long a,char x){
	for(long long i=1;i<=a;i++){
		s+=x;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		add(a,c);
	}
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
