#include<bits/stdc++.h>
using namespace std;
long long a[200010],n;
long long len,sum;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	s=" "+s;
	int sum=0;
	for(int l=1,r=len;l<r;l++,r--){
		if(s[l]!=s[r])sum++;
	}
	cout<<sum;
	return 0;
}