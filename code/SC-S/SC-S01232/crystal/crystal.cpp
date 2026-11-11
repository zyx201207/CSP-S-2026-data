#include<bits/stdc++.h>
using namespace std;
long long qzh[500005];
int ans=0;
long long num=0;
long long sump=0;
int len=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>qzh[i];
	}
	sort(qzh+1,qzh+n+1);
	for(int i=1;i<n;i++){
		qzh[i]=qzh[i+1]-qzh[i];
	}
	qzh[n]=0;
	int lq=1,rq=0;
	while(rq<n-1){
		rq++;
		num=num+qzh[rq]*(rq-lq+1);
		sump+=qzh[rq];
//		cout<<num<<" ";
		while(num>m){
			num-=sump;
			sump-=qzh[lq];
			lq++;
		}
//		cout<<num<<"\n";
		ans=max(ans,rq-lq+1);
//		cout<<lq<<" "<<rq<<"\n";
	}
	cout<<ans+1;
	return 0;
} 