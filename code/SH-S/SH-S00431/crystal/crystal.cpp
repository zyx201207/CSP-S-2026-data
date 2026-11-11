#include<bits/stdc++.h>
using namespace std;
const int Max_N=5e5+10;
long long N,M;
long long S=0;
long long Ans=0;
long long A[Max_N];
long long read(){
	char c;
	long long f=1,cur=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		cur=cur*10+(c^48);
		c=getchar();
	}
	return cur*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	N=read();
	M=read();
	for(long long i=1;i<=N;i++) A[i]=read();
	sort(A+1,A+N+1);
	long long j=1;
	for(long long i=1;i<=N;i++){
		S+=A[i];
		while((i-j+1)*A[i]-S>M&&j<=i){
			S-=A[j];
			j++;
		}
		Ans=max(Ans,i-j+1);
	}
	cout<<Ans;
	return 0;
}
