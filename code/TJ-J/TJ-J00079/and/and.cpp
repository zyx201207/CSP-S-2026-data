#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			if(mx<a[i]){
				mx=a[i];
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int s=a[i]&a[j];
				if(mx<s){
					mx=s;
				}
			}
		}
		cout<<mx;
	}
	if(m==n){
		int mx=a[1];
		for(int i=2;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
	}
	if(m==n-1){
		int mxx=-1;
		int f=1,n1=n,m1=m;
		while(n1--){
			int mx=a[f+1];
			
			int k=0;
			int i=f+2;
			cout<<k;
			while(m1--){
//				mx=mx&a[i];
				
				cout<<mx;
				if(i==n){
					i=1;
				}
				cout<<k;
				k++;
				cout<<k;
			}
			cout<<endl;
			if(mxx<mx){
				mxx=mx;
			}
			f++;
		}
//		cout<<mxx;
	}
	
	return 0;
}

