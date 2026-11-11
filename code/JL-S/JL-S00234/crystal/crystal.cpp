
#include <bits/stdc++.h>
using namespace std;
int sum=0,ans,n,m,a[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	vector <int> v;
	int mid=1,k=1;
	while(sum<=m){
		for(int i=0;i<k;i++){
			if(a[mid]-a[i]<=m-sum){
				sum+=a[mid]-a[i];a[i]=a[mid];
			}
		k++;mid++;
		}
	}
	cout<<mid;
	return 0;
}
