#include<bits/stdc++.h>
using namespace std;
long a[20002];
char c[20002];
string s;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	long long l=s.size(),ys=s.size();
	if(l%2!=0) l=l/2+1;
	else l=l/2;
	for(int i=0;i<l;i++){
		if(s[i]!=s[ys-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
