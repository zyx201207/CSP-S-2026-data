#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ton[3001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		ton[a[i]]++;
	}
	for(int i=0;i<=m;i++){
		if(ton[i]>0){
			cout<<ton[i]<<' ';
		}
	}
	return 0;
}
