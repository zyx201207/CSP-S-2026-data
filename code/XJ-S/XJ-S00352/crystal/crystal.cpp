#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[N],sum[N]={0};
	cin>>n>>m;
	long long mni=1e5+12;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mni){
			mni=a[i];
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==mni){
			continue;
		}
		long long mm=m;
		for(long long j=1;j<=n;j++){
			if(a[i]>=a[j]){
				if(mm>=0){
					int cc=a[i]-a[j];
					mm-=cc;
					sum[i]++;
				}
			}
		}
		if(m<0){
			sum[i]--;
		}
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		if(sum[i]>ma){
			ma=sum[i];
		}
	}
	cout<<ma;
	return 0;
}
