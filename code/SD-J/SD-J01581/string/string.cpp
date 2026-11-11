#include <bits/stdc++.h>
using namespace std;
int n,a,len,ans,last=1;
char s[200005],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		len+=a;
		for(int i=last;i<=last+a-1;i++) s[i]=c;
		last+=a;
	}
	int i=1,j=len;
	while(i<j){
		if(s[i]!=s[j])
			ans++;
		i++,j--;
	}
	cout<<ans;
	return 0;
}
