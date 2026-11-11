#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,c,k,b[200005],sum,d;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sum=n*(n-1)/2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){	
		for(int j=i+1;j<n;j++){
			b[k]=(a[i]&a[j]);
	        for(int z=i+2;z<n;z++){
	        	b[k]=(b[k]&a[z]);
				
			}
			k++;
			
			
			
			
		}
	}
	sort(b,b+sum);
	reverse(b,b+sum);
	
		cout<<b[0];
	
	
	return 0;
}
