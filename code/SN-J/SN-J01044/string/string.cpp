#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,l=0,ans=0;
long long a[N];
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c; 
		l+=a[i];
		for(long long j=1;j<=a[i];j++){
			s+=c;
		}
	}
	long long i=0;
	long long j=l-1;
	while(j>i){
		if(s[i]!=s[j]){
			ans++;
		}
		i++;j--;
	}
	cout<<ans;
	return 0;
}
