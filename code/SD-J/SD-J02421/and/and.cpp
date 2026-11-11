#include<bits/stdc++.h>
using namespace std;
long long j=1,x=1,b[20009],k,n,m,a[20009],max1=-1;
string s,h;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=m;i<=n;i++){
		for(int j=0;j<m;j++){
			
			k=a[i-j];
			x=0;
			while(k){
				s[x]=k%2+'0';
				
				k/=2;
				
				x++;
			}
			
			if(i!=m){
				
				for(int l=1;l<x;l++){
					
					if(h[l]=='0'||s[l]=='0'){
						s[l]='0';
						
					}
				}
			}
			for(int l=1;l<x;l++){
				h[l]=s[l];
			}
			
			
		}
		
		int w=1,v=0;
		for(int l=1;l<=x;l++){
			v+=s[l]-'0';
			for(int r=2;r<=l;r++){
				v*=2;
			}
			b[i]+=v;
			
		}
		
		max1=max(max1,b[i]);
	}
	cout<<max1;
} 
