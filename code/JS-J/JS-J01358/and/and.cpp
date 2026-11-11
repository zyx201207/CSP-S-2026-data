#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int b[100000005];
int d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	d=m;
	for(int i=1;i<=n;i++){
	 cin>>a[i];
	}
	for(int i=n;i>1;i--){
		int c=0;
		m=d;
		while(m>0){
			m-=1;
			c+=1;
			for(int j=i-c;j>=1;j--){
				b[i*j]=a[i]&a[j];
			}
		}
	}
	int maxb=b[1];
	for(int i=2;i<=n*m;i++){
		if(maxb<=b[i]){
			maxb=b[i];
		}
	}
	cout<<maxb;
	return 0;
}
