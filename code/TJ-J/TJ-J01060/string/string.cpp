#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long x[N];
char y[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		for(long long j=1;j<=x[i];j++){
			s+=y[i];
		}
		len+=x[i];
	}
	s=" "+s;
	long long sum1=0;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]){
			sum1++;
		}
	}
	cout<<sum1;
	return 0;
	
	
	/*
	int mxzm=0;
	for(int i=0;i<26;i++){
		if(zimu[i]>mxzm){
			mxzm=zimu[i];
		}
	}
	int idxi=1,idxj=len;
	int xi=1,xj=n;
	long long sum=0;
	int si=x[1];
	int sj=len-x[n];
	while(idxi<=len/2){
		if(y[xi]!=y[xj]){
			sum++;
			idxi+=min(x[xi],x[xj]);
			idxj-=min(x[xi],x[xj]);
		}
		if(idxi>=si){
			xi++;
			si+=x[xi];
		}
		if(idxj<=sj){
			xj--;
			sj-=x[xj];
		}
	}
	cout<<sum;
	return 0;
	*/
	return 0;
}
