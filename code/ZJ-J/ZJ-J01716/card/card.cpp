#include<bits/stdc++.h>
using namespace std;
long long n,m,number[5000005],tong[5000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>number[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			tong[number[j]]++;
		}
	}
	for(int i=1;i<=5000005;i++){
		if(tong[i]!=0){
			cout<<tong[i]<<" ";
		}
	}
	return 0;
}