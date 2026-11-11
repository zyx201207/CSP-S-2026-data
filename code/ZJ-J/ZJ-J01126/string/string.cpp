#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[200010],cnt,ans,n;
char s[5],ch[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],s+1);
		for(int j=1;j<=a[i];j++){
			ch[++cnt]=s[1];
		}
	}
	for(int i=1;;i++){
		ll j=cnt+1-i;
		if(i>j) break;
		if(ch[i]!=ch[j]) ans++;
	}
	printf("%d",ans);
	return 0;
}
