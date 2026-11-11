#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(n+2),b(m+2);
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		long long cnt=0;
		for(long long j=i;j<n;j++){
			long long c[100000],cend=0;
			for(long long p=0;p<n;p++){
				c[cend]=a[j];
				cend++;
				for(long long q=0;q<cend;q++){
					if(a[q]==a[p]){
						cend=q+1;
					}
				}
			}
			for(long long q=0;q<cend;q++){
				if(a[q]==i){
					cnt++;
				}
			}
		}
		cout<<cnt<<" ";
	}
	return 0;
}