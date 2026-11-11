#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
const long long N=1e8+1e7;
long long a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(long long i=0;i<n;i++){
		int t;
		char b;
		cin>>t>>b;
		for(long long j=0;j<t;j++){
			a[cnt+j]=int(b);
		}
		cnt+=t;
	}
	for(long long i=0;i<cnt/2;i++){
		if(a[i]!=a[cnt-1-i])ans++;
	}
	cout<<ans; 
	
	return 0;
}
