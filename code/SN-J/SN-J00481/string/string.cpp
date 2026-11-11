#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n,a,t,ant=0,cnt=1,jh=0;
char c;
char s[1000000];
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a;
	cin>>c;
	for(int j=cnt;j<cnt+a;j++){
		s[j]=c;
	}
	
	cnt=cnt+a;
}
cnt=cnt-1;
//cout<<cnt;
for(int i=0;i<=cnt;i++){
	
	if(s[1+i]!=s[cnt-i]){
		
		jh=jh+1;
	}
	if(1+i==cnt-i||2+i==cnt-i){
		break;
	}
}
//for(int i=1;i<=cnt;i++){
	cout<<jh;
//	cout<<s[i];}
return 0;
}
