#include<bits/stdc++.h>
using namespace std;
#define maxn 15
int c1,c2,S1,S2;
char s1[maxn],s2[maxn];
bool f1,f2,f3,f4;
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
bool side(char a,char b){
	for(char i='A';i<='C';i++){
		for(char j='D';j<='F';j+=2){
			if(i==a && j==b) return false;
			if(i==b && j==a) return false;
		}
	}
	return true;
}
bool nxt(char a,char b){
	if(a=='A' && b=='B') return true;
	if(a=='B' && b=='A') return true;
	if(a=='B' && b=='C') return true;
	if(a=='C' && b=='B') return true;
	if(a=='D' && b=='F') return true;
	if(a=='F' && b=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c1=read();
	scanf("%s",s1+1);
	c2=read();
	scanf("%s",s2+1);
	S1=(s1[1]-'0')*10+(s1[2]-'0');
	S2=(s2[1]-'0')*10+(s2[2]-'0');
	if(c1!=c2){
		f1=0;
	}
	else{
		f1=1;
	}
	if(S1!=S2 || !f1){
		f2=0;
	}
	else{
		f2=1;
	}
	if(!side(s1[3],s2[3]) || !f2){
		f3=0;
	}
	else{
		f3=1;
	}
	if(!nxt(s1[3],s2[3]) || !f3){
		f4=0;
	}
	else{
		f4=1;
	}
	printf("%d%d%d%d",f1,f2,f3,f4);
	return 0;
}
