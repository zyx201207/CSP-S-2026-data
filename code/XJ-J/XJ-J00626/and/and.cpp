#include<bits/stdc++.h>
using namespace std;
	int arr[100000];
	int max1,m,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		int x=arr[i];
		while(x){
			x=x/32;
			s++;
		}
		if(s>m){
			s=m;
			max1=i;
		}
		s=0;
	}
	cout<<arr[max1];
	
	return 0;
}