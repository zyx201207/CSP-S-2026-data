#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200005];
	int n,m,cnt=0;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s;
		for(int j=1;j<=m;j++){
			a[cnt+j]=s;
		}
		cnt+=m;
	}
	int ans=0;
	for(int i=1;i<=cnt/2;i++){
		if(a[i]!=a[cnt-i])ans++;
	}
	cout<<ans;
	return 0;
}
