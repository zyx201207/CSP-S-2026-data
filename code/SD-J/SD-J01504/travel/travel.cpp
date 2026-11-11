#include<bits/stdc++.h>
#define ll long long
#define fori(a,b,c) for(ll i=a;i<=b;i+=c)
#define forj(a,b,c) for(ll j=a;j<=b;j+=c)
using namespace std;
char c1[3],c2[4],s1[3],s2[4];
ll rc,rs,xc,xs;
ll w(char ch){return ch-'0';}
ll change(char ch1,char ch2){
	return w(ch1)*10+w(ch2);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fori(1,2,1)cin>>c1[i];
	fori(1,3,1)cin>>s1[i];
	fori(1,2,1)cin>>c2[i];
	fori(1,3,1)cin>>s2[i];
	rc=change(c1[1],c1[2]);
	rs=change(s1[1],s1[2]);
	xc=change(c2[1],c2[2]);
	xs=change(s2[1],s2[2]);
	if(rc==xc){
		if(rs==xs){
			if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D')){
				if(s1[3]<s2[3])swap(s1[3],s2[3]);
				if((s1[3]==s2[3]+1)&&(s1[3]!='D'&&s2[3]!='C'))printf("1111");
				else printf("1110");
			}
			else printf("1100");
		}
		else printf("1000");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
