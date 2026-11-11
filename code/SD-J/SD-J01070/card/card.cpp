#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[n],k[m+1]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int c[n]={-1},idx=0;
		int l=i,r=n-1;
		while(l<=r){
			while(a[l]!=a[r]){
				r--;
			}
			if(l==r){
				l++;
				r=n-1;
				c[idx]=a[l-1];
				idx++;
			}
			else{
				l=r+1;
				r=n-1;
				c[idx]=a[l-1];
				idx++;
			}
			if(l==n-1){
				c[idx]=a[l];
				idx++;
				l++;
			}
		}
		for(int j=0;j<n-1;j++){
			if(c[j]!=-1)
				cout<<a[j]<<" ";
		}
		cout<<endl;
		for(int j=0;j<n-1;j++){
			if(c[j]!=-1)
				k[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<k[i]<<" ";
	return 0;
}
