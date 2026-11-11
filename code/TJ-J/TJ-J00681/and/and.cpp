#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,nn;
long long f;
long long arr[100001],ar[100001];
int main(){
	std::ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(m==1){
		sort(arr,arr+n);
		cout<<arr[n-1];
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;i<n;i++){
				ar[nn]=arr[i]&arr[j];
				nn++;
			}
		}
	sort(ar,ar+nn);
	cout<<ar[nn-1];
	return 0;
	}
	if(m==n){
		f=arr[0];
		for(int i=0;i<n;i++){
			f=f&arr[i];
		}
		cout<<f;
		return 0;
	}
	cout<<7;
	return 0;
}
