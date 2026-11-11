#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],b[500500],r,c[300300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int ni=1;ni<=n;ni++){
		r=0;
		for(int i=ni;i<=n;i++){
			int p=-1;
			for(int j=1;j<=r;j++){
				if(b[j]==a[i]){
					p=j;
					break;
				}
			}
			if(p==-1){
				r++;
				b[r]=a[i];
			}else{
				r=p;
			}
		}
		for(int i=1;i<=r;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
