#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
string c;
long long ans,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>c;
		for(long long j=1;j<=a[i];j++){
			s+=c;
		}
	}
	for(long long i=0;i<=sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
