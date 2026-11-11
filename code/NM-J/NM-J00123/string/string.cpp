#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,ans=0;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=cnt;j<cnt+a;j++){
			s[j]=c;
		}
		cnt+=a;
	}
	for(int i=1;i<=floor(cnt/2);i++){
		if(s[i]!=s[cnt-i]) ans++;
	}
	cout<<ans;
	return 0;
}
