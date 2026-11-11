#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000000],b[5000000],sum,d,e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int c[m+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	e=n;
	while(e--){
		for(int i=d;i<n;i++){
			b[i]=a[i];
			sum++;
			for(int j=i+1;j<n;j++){
				if(b[i]==a[j])sum=sum-j+i;
			}	
			for(int j=0;j<=m;j++){
				if(sum==j)c[j]++;
			}
		}
		sum=0;
		d++;	
	}
	for(int i=0;i<n;i++){
		cout<<m-i<<" ";
	}
	return 0;
} 
