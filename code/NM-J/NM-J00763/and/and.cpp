#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int a[200005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		int a[200005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					int x=a[i]&a[j];
					mx=max(mx,x);
				}
			}
		}
		cout<<mx;
	}
	if(m==3){
		int a[200005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j && j!=k && i!=k){
						int x=a[i]&a[j]&a[k];
						mx=max(mx,x);
					}
				}
			}
		}
		cout<<mx;
	}
	if(m==4){
		int a[200005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(i!=j && j!=k && i!=k && l!=k && l!=i && l!=j){
							int x=a[i]&a[j]&a[k]&a[l];
							mx=max(mx,x);
						}
					}
				}
			}
		}
		cout<<mx;
	}
	if(m==5){
		int a[200005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int p=1;p<=n;p++){
							if(i!=j && j!=k && i!=k && l!=k && l!=i && l!=j && p!=l&& p!=k && p!=j && p!=i){
								int x=a[i]&a[j]&a[k]&a[l]&a[p];
								mx=max(mx,x);
							}
						}
					}
				}
			}
		}
		cout<<mx;
	}
	return 0;
}
