#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,a[N],ans,sum;
char c[N];
string s;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l=0,r=sum-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
