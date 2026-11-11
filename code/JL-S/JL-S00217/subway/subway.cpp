#include<bits/stdc++.h>
using namespace std;
long long sub[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=n;i++){
		cin>>sub[i];
	}
	while(q>=0){
		q--;
		long long k,sum=0;
		cin>>k;
		long long ko[500000]={0};
		long long kt[500000]={0};
		for(long long i=1;i<=k;i++){
			cin>>ko[i]>>kt[i];
		}
		long long begin=0,fina=0;
		cin >>begin>>fina;
		for(long long i=1;i<=k;i++){
			if(ko[i]==begin){
				sum=sum+kt[i];
			}
			if(ko[i]==fina){
				sum=sum+kt[i];
		}
		cout<<sum<<endl;
	}
}
	return 0;
}
