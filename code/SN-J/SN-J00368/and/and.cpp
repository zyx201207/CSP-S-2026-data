#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int max0=0;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k=0;
		while((i<=n-1&&k<=n-2)||k<=n-1){
			int t=a[i];
			int s=1;
			if(k==i&&i!=1){
				k=i+1;
			}else if(i==0&&k==i){
				k=1;
			}
			while(s<m){
				if(k==i){
					k++;
				}
				if(k>n){
					break;
				}
				t=t&a[k];
				k++;
				s++;
				if(k>n){
					break;
				}
			}
			if(max0<t){
				max0=t;
			}
		}
	}
	cout<<max0;
	return 0; 
} 
