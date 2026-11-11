#include<bits/stdc++.h>
using namespace std;
int n,cnt;long long ans;
struct ZZL{
	long long a;char c;
}b[200005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();char y;
		cin>>y;
		if(y==b[cnt].c)b[cnt].a+=x;
		else b[++cnt]=(ZZL){x,y};
	}
	for(int i=1,j=cnt;i<j;){
		if(b[i].c!=b[j].c){
			if(b[i].a>b[j].a)b[i].a-=b[j].a,ans+=b[j].a,j--;
			else if(b[i].a==b[j].a)ans+=b[i].a,i++,j--;
			else b[j].a-=b[i].a,ans+=b[i].a,i++;
		}else{
			if(b[i].a==b[j].a)i++,j--;
			else if(b[i].a>b[j].a)b[i].a-=b[j].a,j--;
			else b[j].a-=b[i].a,i++;
		} 
	}
	cout<<ans;
	return 0;
}//zhenzhen double 
