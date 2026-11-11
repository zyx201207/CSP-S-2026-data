#include<bits/stdc++.h>
using namespace std;
//#define long long long long
//#define long long unsigned long long
const long long maxn=5e5+13,maxm=3e5+13;
long long a[maxn],sum[maxm],b[maxn],a1[maxn];
//bool pd[maxm];
//priority_queue<int> sb;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		//a1[i]=a[i];
	}
	/*for(long long i=n;i>0;i--){
		
	}*/
	long long l;
	for(long long x=1;x<=n;x++){
		memset(a1,0,sizeof(a1));
		//memset(pd,0,sizeof(pd));
		memset(b,0,sizeof(b));
		if(x==n){
			sum[a[x]]++;
			continue;
		}
		for(long long i=x,j=1;i<=n;i++,j++){
			a1[j]=a[i];
			if(b[a1[j]]!=0){
				j=b[a1[j]];
			}
			//cout<<j<<"e\n";
			b[a1[j]]=j;
			if(i==n){
				l=j;
			}
		}
		for(long long i=1;i<=l;i++){
			//cout<<a1[i];
			sum[a1[i]]++;
		}
		//cout<<"\n";
	}
	for(long long i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
