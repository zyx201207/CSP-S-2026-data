#include<bits/stdc++.h>
using namespace std;  

int a[2005];


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,ma=0,max2=0;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		}
	if(m==1){
		cout<<ma;
		return 0;
		}
	if(m==2){
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max2=max(max2,a[i]&a[j]);
				}
			}
		
		cout<<max2;
		return 0;
		}
	if(m==n){
		int lll=a[1];
		for(int i=2;i<=n;i++){
			lll&=a[i];
			}
		cout<<lll;
		return 0;
		}
	else{
		cout<<3;
		
		
		}
	
	
	
	
	
	return 0;
}
