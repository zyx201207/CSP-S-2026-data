#include<bits/stdc++.h>
using namespace std;
int arr[20015];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int maxm=-99999;
	for(int z=0;z<n;z++){
		for(int i=0;i<n;i++){
			int h=arr[z];
			for(int j=i;j<=m;j++){
				h=h and arr[j];
			}
			maxm=max(h,maxm);
		}
	}
	cout<<maxm;
return 0;
}
