#include <bits/stdc++.h>
using namespace std;
int n,a[10000005],cnt,ans,r,l;
char c[20000005],s[20000005];
bool w(){
	if(s[r]=s[l]){
		s[r]=s[l];
		ans++;
		return w;
	}
	l++,r--;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>n;
		for(int j=1;j<=a[i];j++){
			++cnt=a[i];
		}
	}
	cout<<w;
	return 0;
}
