#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
long long cnt=1;
char b[N];
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
	long long n;
	cin>>n;
	int ans=0;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			b[cnt++]=c; 
		}
		if(b[i]!=b[n-i+1]){
			ans++;
		}else{
			continue;
		}
	}
	cout<<ans;
    return 0;
}

