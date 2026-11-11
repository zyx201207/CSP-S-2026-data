#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
int l,c;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//freopen("Tracel.in","r",stdin);
	//freopen("travel1.in","r",stdin);
	//freopen("Tracel.out","w",stdout);
	//freopen("travel1.out","w",stdout);
	//wo neng shang ma
	l=read();
	cin>>s1;
	c=read();
	cin>>s2;
	if(l==c){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				printf("1");
				if(abs(s1[2]-s2[2])==1)printf("1\n");
				else printf("0\n");
			}
			else printf("00\n");
		}
		else printf("000\n");
	}
	else printf("0000\n");
	return 0;
}
