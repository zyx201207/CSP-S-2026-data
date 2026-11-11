#include<bits/stdc++.h>
using namespace std;
char ch[200005];
int a[200005],n;
long long st=1,en,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		loop:scanf("%c",&ch[i]);
		if(ch[i]==' '||ch[i]=='\n')goto loop;
	}
	en=n;
	while(st<en){
		if(ch[st]==ch[en]){
			if(a[st]>a[en])a[st]-=a[en],a[en]=0,en--;
			else if(a[st]==a[en])a[st]=a[en]=0,st++,en--;
			else a[en]-=a[st],a[st]=0,st++;
		}else{
			if(a[st]>a[en])a[st]-=a[en],ans+=a[en],a[en]=0,en--;
			else if(a[st]==a[en])ans+=a[st],a[st]=a[en]=0,st++,en--;
			else a[en]-=a[st],ans+=a[st],a[st]=0,st++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
