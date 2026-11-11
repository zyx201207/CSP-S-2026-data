#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int x;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=i;j>=1;j--){
			sum+=a[j];
		}
		cout<<sum<<" ";
	}

	

	return 0;
} 
