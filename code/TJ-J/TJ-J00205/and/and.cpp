#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int maxx=0;
		for(int i=1;i<=n-1;i++){
				int andd=(a[i]&a[i+1]);
				if(maxx<andd) maxx=andd;	
		}
		cout<<maxx;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n-1;j++){
				int andd=(a[j]&a[j+1]);
				if(maxx<andd) maxx=andd;
			}
				
		}
		cout<<maxx;
	}
	
	return 0;
}
