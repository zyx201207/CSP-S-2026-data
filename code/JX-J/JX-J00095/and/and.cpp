#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t,maxx=-100000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}else if(m==n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++){
				t=a[i]&a[j];
				maxx=max(t,maxx);
			}
		}
		cout<<maxx;
	}
}
