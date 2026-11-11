#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N];
char s[N],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=(c[i]-'a');
	}
	for(int i=0;i<n;i++){
		if(sum==(n*(c[i]-'a'))){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	return 0;
}

