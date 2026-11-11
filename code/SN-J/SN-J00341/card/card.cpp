#include <bits/stdc++.h>
using namespace std;
long long mj6767[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long k[100000];
	for(long long i=1;i<=n;i++){
		cin >> k[i];
	}
	for(long long i=1;i<=n;i++){
		long long num=0; 
		long long mj[100000];
		long long r=0;
		bool qq[100000];
		for(long long kkkg=1;kkkg<=m;kkkg++){
			qq[kkkg]=0;
		}
		for(long long j=i;j<=n;j++){
			r++;
			long long p=k[j];
			if(qq[p]==0){
			qq[p]=1;
			mj[r]=k[j];
			}
			else{
				while(mj[r]!=p){
					qq[mj[r]]=0;
					if(mj[r]==p){
						qq[mj[r]]=1;
					}
					r--;
				}
			}
		}	
		for(long long i=1;i<=m;i++){
			if(qq[i]==1){
				mj6767[i]++;
			}
		}
		}
	for(long long i=1;i<=m;i++){
	cout << mj6767[i] << " ";
	}
	return 0;
		
	}
