#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[100005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=-1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]&a[j]>max){
				max=a[i]&a[j];
			} 
		}
	}
	cout<<max;
	return 0;
}
