#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000000001],z=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sort(a+1,a+1+n);
		
	}
	while(m!=0){
		a[1]=a[1]+1;
	m--;
		sort(a+1,a+1+n);
		
	
		
		
		
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			z++;
		}
	}
	cout<<z+1;
	
	return 0;
} 
