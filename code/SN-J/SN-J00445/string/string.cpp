#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
string s="";
long long l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i]>>c[i];
    	l+=a[i];
    	for(int j=1;j<=a[i];j++) s+=c[i];
	}for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}cout<<ans;
	return 0;
}
