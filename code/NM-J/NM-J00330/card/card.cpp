#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],b[100010],c[100010],zs[100010],wp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(m==1){
		cout<<n;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				c[a[n]]++;
			}
			else{
				c[1]++;
				c[2]++;
			}
		}
		cout<<c[1]<<" "<<c[2];
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			wp=0;
			for(int j=i;j<=n;j++){
				if(b[a[j]]-zs[a[j]]>=2&&wp==0){
					wp=a[j];
				}
				else{
					if(wp){
						if(wp==a[j]){
							wp=0;
						}
						zs[a[j]]++;
					}
				}
			}
			for(int j=1;j<=m;j++){
				if(b[j]-zs[j]>0){
					c[j]++;
				}
				zs[j]=0;
			}
			b[a[i]]--;
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				c[a[i]]+=i;
			}
		}
		c[n]=n;
		for(int i=1;i<=n;i++){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
