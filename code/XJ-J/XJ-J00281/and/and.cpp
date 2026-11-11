#include <bits/stdc++.h>
using namespace std;
long long m,n;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(m==n){
		int max=a[0];
		for(int i=1;i<n;i++){
			max=max&a[i];
		}
		cout<<max;
		return 0;
	}
	if(m==1){
		int max=0;
		for(int i=0;i<n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
		return 0;
	}
	if(m==2){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]&a[j]>max){
					max=a[i]&a[j];
				}
			}
		}
		cout<<max;
		return 0;
	}
	return 0;
}