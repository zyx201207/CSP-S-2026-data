#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mmax=0,mand=2147483647;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mmmax=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		mand=mand&a[i];
	}
	if(m==1){
		cout<<mmax;
	}
	else if(m==n){
		cout<<mand;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[i]&a[j])>mmmax&&i!=j){
					mmmax=a[i]&a[j];
				}
			}
		}
		cout<<mmmax;
	}
	return 0;
}

