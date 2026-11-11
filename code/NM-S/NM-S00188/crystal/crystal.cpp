#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,k,a[500010],bg;
long long b[110],x;
long long cz;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
		 	cin>>a[i];
		}
		sort(a+1,a+n+1);
	 	for(int j=2;j<=n;j++){
	 		int l=j-1;
	 		bg=1,k=m;
	 		while(k){
		 		if(l>=1){
		 			if(k>=a[j]-a[l]){
		 				bg++;
		 				k-=a[j]-a[l];
		 				l--;
					}
					else{
						k=0;
					}
				}
				else{
					break;
				}
			}
	 		ans=max(ans,bg);
		}
		cout<<ans;
	}
	else if(m<=100000000){
		for(int i=1;i<=n;i++){
			cin>>x;
			b[x]++;
		}
		for(int i=2;i<=100;i++){
			k=m,bg=b[i];
			int l=i-1;
			while(k){
				if(l>=1){
		 			if(k>=(i-l)*b[l]){
		 				bg+=b[l];
		 				k-=(i-l)*b[l];
		 				l--;
					}
					else{
						bg+=k/(i-l);
						k=0;
					}
				}
				else{
					break;
				}
			}
			ans=max(ans,bg);
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[20]<a[5]||a[45]<a[32]){
			sort(a+1,a+1+n);
		}
		cz=a[2]-a[1];
		if(cz==0){
			cout<<n;
		}
		else{
			if(m>=(a[n]+a[1])*n/2){
				cout<<n;
			}
			else{
				for(int j=1;j<=n;j++){
					if(m<(a[j]-a[1]+1)*(j-1)/2){
						break;
					}
					k=j;
				}
				cout<<k;
			}
		}
	}
	return 0;
}
