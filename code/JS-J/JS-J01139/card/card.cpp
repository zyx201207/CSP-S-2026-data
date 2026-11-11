#include<bits/stdc++.h>
using namespace std;
long shu[300001],wei[300001],num[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long pai[n+1];
	for(int i=1;i<=n;i++){
		cin>>pai[i];
	}
		long you=0;
	while(you<n){
		you++;
		for(int i=1;i<=m;i++){
			shu[i]=0;
			wei[i]=0;
		}
		for(int i=you;i<=n;i++){
			shu[pai[i]]++;
			if(shu[pai[i]]==2){
				for(int j=wei[pai[i]]+1;j<=i;j++){
					shu[pai[j]]--;
				}
			}
			wei[pai[i]]=i;
		}
		for(int i=1;i<=n;i++){
			num[i]+=shu[i];
		}
		
		
	}
	for(int i=1;i<=m;i++){
	cout<<num[i]<<' ';
}
	return 0;
	}
