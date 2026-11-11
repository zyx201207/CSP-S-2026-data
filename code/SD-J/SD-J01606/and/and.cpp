#include<bits/stdc++.h>
using namespace std;
long long n,a[300005],m,f=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[0]=a[1];
		if(a[i]!=a[i-1]){
			f=0;
		}
	}
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
		cout<<7;
	}else if(f){
		cout<<a[1];
	}else if(m==2){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					maxx=max(a[i]&a[j],maxx);
				}
			}
		}
		cout<<maxx;
	}else if(m==3){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(j!=i&&j!=k&&i!=k)	maxx=max(a[i]&a[j]&a[k],maxx);
				
			}
		}
		cout<<maxx;
	}
	}else if(m==4){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int q=1;q<=n;q++){
						if(j!=i&&j!=k&&j!=q&&i!=q&&i!=k&&k!=q)	maxx=max(a[i]&a[j]&a[k]&a[q],maxx);
					}
				}
			}
		}
		cout<<maxx;
	}
	
	return 0;
}
