#include<cstdio>
#include<string>
#include<cstring>

namespace zxz{
	char c1[55],s1[55],c2[55],s2[55];
	int cr[5],ln[5],rw[5];
	bool a,b,c,d;
	void solve(){
		scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
		s1[3]=s1[3]-'A'+1;s2[3]=s2[3]-'A'+1;
		if(s1[3]==6) s1[3]=5;
		if(s2[3]==6) s2[3]=5;
		a=b=c=d=true;
		for(int i=1;i<=2;i++) if(c1[i]!=c2[i]) a=false;
		for(int i=1;i<=2;i++) if(s1[i]!=s2[i]) b=false;
		if((s1[3]>=1&&s1[3]<=3)^(s2[3]>=1&&s2[3]<=3)) c=false;
		if(s1[3]-s2[3]!=1&&s2[3]-s1[3]!=1) d=false;
		b&=a,c&=b,d&=c;
		printf("%d%d%d%d\n",a,b,c,d);		
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	zxz::solve();
	return 0;
}
