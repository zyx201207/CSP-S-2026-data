#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];	
	}
	if(m==n){
		int cn=0;
		for (int i=1;i<=n;i++){
			cn=cn&a[i];
		}
		cout<<cn;
	}
	if(m==2){
		int cn=0;
		for(int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if(a[i]&a[j]>cn){
					cn=a[i]&a[j];
				}
			}
		}
		cout<<cn;
	}
	return 0;
}
