#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, m, a[N], mx, mxx;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==2){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				mxx=max(mxx,a[i]&a[j]);
			}
		}
		cout<<mxx;
		return 0;
	}else if(m==3){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				for(int k=1;k<=n;k++){
					mxx=max(mxx,a[i]&a[j]&a[k]);
				}
			}
		}		
	}
	else if(m==4){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						mxx=max(mxx,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}		
	}	
	else if(m==5){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int q=1;q<=n;q++){
							int er=a[i]&a[j]&a[k]&a[l]&&a[q];
							mxx=max(mxx,er);
						}
					}
				}
			}
		}		
	}else{
		cout<<mx-n+1;
	}
	return 0;	
}