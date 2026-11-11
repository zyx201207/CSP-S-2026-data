#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005],b[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
		int wer;
		wer=a[i];
		int qwq=1;
		int qwe=0;
		while(wer>0){
			qwe=qwe+wer%2*qwq;
			wer=wer/2;
			qwq*=10;
		}
		while(wer>0){
			qwe=qwe+wer%2*qwq;
			wer=wer/2;
			qwq*=10;
		}
		b[i]=qwe;
	}
	int sum=0,ans=0,qw=1;
	for (long long i=1;i<=n;i++){
		for (long long j=i+1;j<=n;j++){
			ans=0,qw=1;
			int qa=b[i],qb=b[j];
			cout<<qa<<' '<<qb<<' '<<endl;
			while(qa>0){
				cout<<(qa%10 and qb%10)<<' ';
				if((qa%10 and qb%10)==1){
					
					ans=ans+qw;
				}
				cout<<ans<<' ';
				qw=qw*2;
				qa=qa/10;
				qb=qb/10;
			}
			cout<<ans<<'\n';
			sum=max(sum,ans);
		}
	}
	cout<<sum;
	return 0;
} 
