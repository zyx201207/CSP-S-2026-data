#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0,m1max=0,mnmax,m2max=0;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>m1max){
			m1max=a[i];
		}
	}
	if(m==1){
		cout<<m1max;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>m2max){
					m2max=a[i]&a[j];
				}
			}
		}
		cout<<m2max;
	} 
	return 0;
}
