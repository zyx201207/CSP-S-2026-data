#include<bits/stdc++.h>
using namespace std;
long long n,a,len,ans,cnt;
char c,b[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		while(a--){
			b[cnt]=c;
			cnt++;
		}
	}
	int l=0,r=len-1;
	while(l<=r){
		if(b[l]!=b[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
} 
