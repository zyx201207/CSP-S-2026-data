#include<bits/stdc++.h>
using namespace std;
const int N=2e+6;
int a[N+10];
bool sxd(int l,int r,int d){
	if(r-l<=2) return 0;
	else{
		int k;
		int num=1;
		for(int i=l;i<=r;i++){
			for(int j=i+1;j<=r;j++){
				if(a[j]-a[i]>d){
					k=j-1;
					break;
				}
			}
			if(k-i>=2){
				for(int j=i+1;j<k;j++){
					for(int m=k+1;m<=r;m++){
						if(a[m]-a[j]<=d){
							num++;
						}
					}	
				}
			}
			
			if(num>2) return 0; 
		}
		
		if(num==2) return 1;
		else return 0;
	} 
} 
bool mz_a(int n){
	int gc=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=gc) return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t;
	
	while(t--){
		memset(a,0,sizeof(a));
		int n,d; cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		if(mz_a(n)){
			int gc=a[2]-a[1];
			int cz=d/gc;
			long long num=0;
			for(int i=1;i<=n-cz-1;i++){
				for(int j=i+cz+1;j<=n;j++){
					if((a[j]-a[i])%d!=0){
						num++;
					}
					
				}
			}
			cout<<num<<endl;
		}else{
			long long num=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(sxd(i,j,d)){
						num++;
					}
				}
			}
			cout<<num<<endl;
		}
	}
	
	return 0;
}
