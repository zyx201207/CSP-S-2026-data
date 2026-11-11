#include<bits/stdc++.h>
using namespace std;
int n,r,sum=0;
long long m,a[500005],cut[500005];
long long ave;
int main(){
//	freopen("crystal.in" ,"r",stdin );
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
		ave+=a[i];
	}
	for(int i=0;i<n;++i){
		if(a[i]>=ave/n){
			r=i;break;
		}
	}
	for(int i=0;i<n;++i){
		cut[i]=a[r]-a[i];
	}sort(cut,cut+n);
	int i=0;
	while(m>=0 && i<n){
		i++;
		if(cut[i]>=0){
			m-=cut[i];
			sum++;
		}
	}
	cout<<sum-1<<'\n';
	return 0;
}
