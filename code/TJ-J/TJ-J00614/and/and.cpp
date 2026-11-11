#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2*114514],mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<=20){
		if(m==1){
			for(int i=0;i<n;i++) mx=max(mx,a[i]);
			cout<<mx;
		}
		
		if(m==2){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					mx=max(mx,(a[i]&a[j]));
				}
			}
			cout<<mx;
		}
		
		if(m==3){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++)
						mx=max(mx,(a[i]&a[j]&a[k]));
				}
			}
			cout<<mx;
		}
		
		if(m==4){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++)
						for(int i1=k+1;i1<n;i1++)
							mx=max(mx,(a[i]&a[j]&a[k]&a[i1]));
				}
			}
			cout<<mx;
		}
		
		if(m==5){
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					for(int k=j+1;k<n;k++)
						for(int i1=k+1;i1<n;i1++)
							for(int j1=i1+1;j1<n;j1++)
								mx=max(mx,(a[i]&a[j]&a[k]&a[i1]&a[j1]));
				
			cout<<mx;
		}
	
		if(m==6){
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					for(int k=j+1;k<n;k++)
						for(int i1=k+1;i1<n;i1++)
							for(int j1=i1+1;j1<n;j1++)
								for(int k1=j1+1;k1<n;k1++)
								mx=max(mx,(a[i]&a[j]&a[k]&a[i1]&a[j1]&a[k1]));
				
			cout<<mx;
		}
	
		if(m==7){
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					for(int k=j+1;k<n;k++)
						for(int i1=k+1;i1<n;i1++)
							for(int j1=i1+1;j1<n;j1++)
								for(int k1=j1+1;k1<n;k1++)
								    for(int i2=k1+1;i2<n;i2++)
										mx=max(mx,(a[i]&a[j]&a[k]&a[i1]&a[j1]&a[k1]&a[i2]));
				
			cout<<mx;
		}
	}
	
	
	if(n>20&&n<=2000){
		
		if(m==1){
			for(int i=0;i<n;i++) mx=max(mx,a[i]);
			cout<<mx;
		}
		
		if(m==2){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					mx=max(mx,(a[i]&a[j]));
				}
			}
			cout<<mx;
		}
		
		if(m==n){
			for(int i=0;i<n;i++) mx=(mx&a[i]);
			cout<<mx;
		}
		
	}
	return 0;
} 
