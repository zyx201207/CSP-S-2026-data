#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
int a[200005];
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	int l=int(s.size());
	for(long long i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
