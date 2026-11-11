#include<cstdio>
#include<algorithm>
struct letter{
	int a;
	char c;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&s[i].a);
		scanf(" %c",&s[i].c);
	}
	long long ans=0;
	for (int nowl=1,nowr=n;nowl<nowr;){
		int x=std::min(s[nowl].a,s[nowr].a);
		if (s[nowl].c!=s[nowr].c){
			ans+=x;
		}
		if (s[nowl].a<s[nowr].a){
			nowl++;
			s[nowr].a-=x;
		}
		else if (s[nowl].a>s[nowr].a){
			nowr--;
			s[nowl].a-=x;
		}
		else {
			nowl++;
			nowr--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
