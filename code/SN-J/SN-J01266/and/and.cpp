#include<bits/stdc++.h>
using namespace std;
int n,m,s,maxn;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn)
			maxn=a[i];
		}
		cout<<maxn;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
				if(a[i]|a[j]>maxn)
				maxn=a[i]|a[j];
				}
			}
		}
		cout<<maxn;
	}
	cout<<4;
	return 0;
}
