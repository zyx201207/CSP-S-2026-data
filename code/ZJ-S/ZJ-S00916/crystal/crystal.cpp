#include<bits/stdc++.h>
using namespace std;
long long m,n,c[500005],ma=0,l,r,a,b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(long long i=1;i<=n;i++){
		a=m;
		l=i-1;
		r=i+1;
		b=1;
		while(a>0){
			if(l==0 && r==n+1){
				break;
			}
			else if(l==0){
				if(a>=(c[r]-c[i])){
					a-=c[r]-c[i];
					b++;
					r++;
				}
				else{
					a=0;
				}
			}
			else if(r==n+1){
				if(a>=(c[i]-c[l])){
					a-=c[i]-c[l];
					b++;
					l--;
				}
				else{
					a=0;
				}
			}
			else{
				if((c[r]-c[i])>(c[i]-c[l])){
					if(a>=(c[i]-c[l])){
						a-=c[i]-c[l];
						b++;
						l--;
					}
					else{
						a=0;
					}
				}
				else{
					if(a>=(c[r]-c[i])){
						a-=c[r]-c[i];
						b++;
						r++;
					}
					else{
						a=0;
					}
				}
			}
		}
		ma=max(ma,b);
	}
	cout<<ma;
} 
