#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,t;
int main (){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	cin>>n>>t;
	int b[100005]; 
	for(int i=1;i<=t;i++){
		int n,d,a[200005];
		cin>>n>>d;
		int sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		} for(int j=1;j<=n-3;j++){
			for(int q=j;q<=n;q++){
				if(q-j==3&&a[q]-a[j]>d){
					if(a[q-1]-a[j]<=d&&a[q]-a[j+1]<=d){
						sum++;
					}
				}
			}
		}
		b[i]=sum;
	}
	for(int i=1;i<=t;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}
