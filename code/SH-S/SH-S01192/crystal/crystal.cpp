#include<cstdio>
#include<algorithm>
using namespace std;
long long A[500010],S[500010],M;
int N;
inline long long readin(){
	long long num=0;
	char ch=' ';
	long long sgn=1;
	while(ch==' '||ch=='\n'||ch=='\r')ch=getc(stdin);
	if(ch!=EOF)if(ch=='-')sgn=-1,ch=getc(stdin);
	while('0'<=ch&&ch<='9'&&ch!=EOF){
		num=((num<<1)+(num<<3))+((long long)ch-'0');
		ch=getc(stdin);
	}
	return num*sgn;
}
#define needed(l,r) (((r)-(l)+1)*A[r]-(S[r]-S[(l)-1]))
int solve(){
	int ans=1;
	for(int l=1,r=1;r<=N;r++){
		while(needed(l,r)>M)l++;
		if(r-l+1>ans)ans=r-l+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	N=readin();
	M=readin();
	A[0]=S[0]=0;
	for(int i=1;i<=N;i++)A[i]=readin();
	sort(&A[1],&A[N+1]); 
	for(int i=1;i<=N;i++)S[i]=A[i]+S[i-1];
	printf("%d",solve());
	return 0;
}
