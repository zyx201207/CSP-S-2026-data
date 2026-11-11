#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[500005],s=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n];
	}
	else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>s){
					s=a[i]&a[j];
				}
			}
		}
		cout<<s;
	}
	else{
		cout<<1;
	}
	return 0;
}
