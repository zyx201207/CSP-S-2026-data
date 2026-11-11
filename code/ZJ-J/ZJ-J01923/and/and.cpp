#include<bits/stdc++.h>
using namespace std;
int n,m,a[100086],MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>MAX)MAX=a[i];
	}
	if(m==1){
		cout<<MAX;
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++){
			a[i]&=a[i+1];
			a[i+1]=a[i];
		}
		cout<<a[n];
		return 0;
	}
	MAX=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			int x=a[i];
			int b=a[i]&=a[j];
			a[i]=x;
			if(b>MAX){
				MAX=b;//cout<<i<<" "<<j<<endl;
			}
			}
		}
		cout<<MAX;
	}
	return 0;
}
/*4 2
 3 15 12 12*/
