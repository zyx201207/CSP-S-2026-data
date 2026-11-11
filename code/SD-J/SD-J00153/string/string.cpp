#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],len,ans;
char c[1000010];
string sa,sb;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}for(int i=1,j=1;i<=ceil(len/2);i++){
		if(a[j]>0)a[j]--;
		else j++;
		sa[i]=c[j];
	}for(int i=1,j=n;i<=ceil(len/2);i++){
		if(a[j]>0)a[j]--;
		else j--;
		sb[i]=c[j];
	}for(int i=1;i<=ceil(len/2);i++){
		ans+=(sa[i]!=sb[i]);
	}cout<<ans;
	return 0;
}
