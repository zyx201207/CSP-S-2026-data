#include<bits/stdc++.h>
using namespace std;
long long b[2002000],jy[2020001],d,c,n,m,h[2000100],po;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>po;
	while(po>0){
		po--;
		cin>>n>>d;
		
		for(int i=1; i<=n; i++){
			scanf("%lld",&jy[i]);
			b[i]=jy[i]-jy[i-1];
		} 
		b[1]=0;
		long long l=1,r=1,hl=0,hr=0;
		for(int i=1; i<=n ;i++){
			hr-=b[i];
			while(hr+b[r]<=d && r<=n){
				r++;
				hr+=b[r];
				if(hr>d){
					r--;
					hr-=b[r];
					break;
				}
			}
			if(hl+b[i]>d){
				while(l<=r && hl+b[i]>d){
					
					l++;
					hl-=b[l];
				}
			}
			else hl+=b[i];
			h[l]+=1;
			h[r+1]-=1;
		}
		long long an=0,k=0;
		for(int i=0; i<=n; i++){
			k+=h[i];
			cout<<k<<" ";
			if(k==2) an++; 
		}
		cout<<endl;
		cout<<an<<endl;
	}
	
	
	return 0;
} 
