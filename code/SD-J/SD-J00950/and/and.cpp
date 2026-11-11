#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxx) maxx=a[i];
		}
	}
	if(m==2){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==j) k++;
				if(a[j]&a[k]>maxx) maxx=a[j]&a[k];
			}
		}
	}
	if(m==3){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==j) k++;
				for(int m=1;m<=n;m++){
					if(m==k) m++;
					if(a[j]&a[k]&a[m]>maxx) maxx=a[j]&a[k]&a[m];
				}
			}
		}
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
	}
	if(m==n-1){
		maxx=a[1];
		for(int i=2;i<=n-1;i++){
			maxx=maxx&a[i];
		}
	}
	cout<<maxx<<"\n";
	return 0;
}
