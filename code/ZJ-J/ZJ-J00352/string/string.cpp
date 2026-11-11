#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
string s=" ";
int n;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long L=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		L+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	if(L>100000000){
		cout<<L/2;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=L/2;i++){
		if(s[i]!=s[L+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}