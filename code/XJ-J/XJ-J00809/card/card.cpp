#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[N],um[N]={0};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long s=a[j];
			um[s]++;
			if(um[s]>i){
				for(long long f=i;f<j;f++){
					if(a[f]==s){
						for(long long k=f;k<j;k++){
							long long sa=a[k];
							um[sa]--;
						}
					}
				}
			}
			
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<um[i]<<" ";
	}
	return 0;
}
