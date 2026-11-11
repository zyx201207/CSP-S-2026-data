#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n;
	int m;
	int a[10000];
	cin>>n;
	cin>>m;
	int ji=0;
	int maxn=1001;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		if(n==1){
			cout<<a[1];
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]){
				maxn==a[i];
			}else if(a[i]<a[i-1]){
				maxn==a[i-1];
			}
		}
		cout<<maxn;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			ji++;
		}
	}
	if(ji==n-1){
		cout<<a[1];
	}
	return 0;
}
