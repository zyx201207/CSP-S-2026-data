#include <bits/stdc++.h>
using namespace std;
int a[1000000005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k=0;
		cin>>a[i];
		if(k!=a[i]){
			continue;
		}else{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
