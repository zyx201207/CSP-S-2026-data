#include<bits/stdc++.h>
using namespace std;
int a[500001],weizih[500003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++){
			if(a[i]==j){
				sum++;
				if(a[i+1]!=j){
					if(sum%2==0){
//						cout<<sum<<" ";
						cout<<sum/2<<" ";
					}
					else{
						cout<<i<<" ";
//						cout<<sum<<" ";
					}
					sum=0;
				}
			}
		}
	}

	return 0;
}

