#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int sum=a[n-k],j=n-k,f=0;
	for(int i=1;i<k;i++){
		sum=sum&a[j+1];
		if(sum==0){
			f++;
			sum=a[n-k-f];
			j=n-k-f;
			for(int z=n-k-f;z<n-f;z++){
				a[z]=a[z+1];
			}
			i=1;
		}
		j++;
	}
	cout<<sum;
	return 0;
} 
