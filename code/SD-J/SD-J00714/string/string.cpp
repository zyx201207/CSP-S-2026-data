#include<bits/stdc++.h>
using namespace std;
const int N=2e5; 
int n,a[N];
long long ans=0,sum=0;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		sum+=a[i];
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
