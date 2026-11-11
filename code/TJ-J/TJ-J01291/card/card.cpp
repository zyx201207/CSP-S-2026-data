#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,c,k,b[200005],sum,d;

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	sum=n*(n-1)/2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){	
		for(int j=i+1;j<n;j++){
		d=j;
			b[k]=(a[i]&a[d]);
			for(int z=0;z<m;z++){
				b[k]=b[k]&a[d];
				d++;
			}
			
			
			k++;
		}
	}
	sort(b,b+sum);
	reverse(b,b+sum);
	for(int i=0;i<n;i++){
		cout<<b[i];
	}
	
	return 0;
}
