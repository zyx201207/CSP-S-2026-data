#include<bits/stdc++.h> 
using namespace std;
int n;
string s[100000010];
char c;
long long sum,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long a[n+3];
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c;
		d+=a[i];
		for(int j=d-a[i]+1;j<=d;j++){
			s[j]+=c;
		}
	}
	for(int i=1;i<=d;i++){
		if(s[i]!=s[d-i+1]) sum++;
	}
	cout << sum/2;
	return 0;
}
