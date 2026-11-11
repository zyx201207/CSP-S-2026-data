#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a;
	string c;
	string b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			b+=c;
		}
	}
	int len=b.length();
	int num=len/2;
	int ans=0;
	for(int i=0;i<=num;i++){
		if(b[i]!=b[len-i-1]){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
