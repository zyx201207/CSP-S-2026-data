#include<bits/stdc++.h>
using namespace std;
long long a[2000010],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1; i<=n; i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}else if(m==2){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}else if(m==3){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					maxx=max(maxx,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<maxx;
	}else if(m==4){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int h=k+1; h<=n; h++){
						maxx=max(maxx,(a[i]&a[j]&a[k]&a[h]));
					}
				}
			}
		}
		cout<<maxx;
	}else{
		cout<<0;
	}
	return 0;
}
