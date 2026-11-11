#include<bits/stdc++.h>
using namespace std;
const int mn=2e6+5;
long long f[mn],a[mn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==2){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&i!=j;j++){
				cnt=max(cnt,(a[i]&a[j]));
			}
		}
		cout<<cnt;
	} else{
			for(int i=1;i<=m;i++){
		f[i]=a[n];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=2;j--){
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<f[i]<<" "; 
//	}
//	cout<<"\n";
	printf("%d",f[m]);
	}

	return 0;
}
