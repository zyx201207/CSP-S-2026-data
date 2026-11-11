#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
char b[500005];
long long x,z;
char y;
long long cntz;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(x!=0){
			if(z==0){
				if(b[--r]!=y){
					cntz+=min(x,a[r]);
				}
				if(x>a[r]){
					x=x-a[r];
					y=y;
					z=0;
				}
				else if(x==a[r]){
					x=0;
					l++;
					r--;
				} 
				else{
					x=a[r]-x;
					y=b[r];
					z=1;
				}
			}
			else{
				if(b[++l]!=y){
					cntz+=min(a[l],x);
				}
				if(a[l]>x){
					x=a[l]-x;
					y=b[l];
					z=0;
				}
				else if(a[l]==x){
					x=0;
					l++;
					r--;
				} 
				else{
					x=x-a[l];
					y=y;
					z=1;
				}
			}
		}
		else if(b[l]!=b[r]){
			cntz+=min(a[l],a[r]);
			if(a[l]>a[r]){
				x=a[l]-a[r];
				y=b[l];
				z=0;
			}
			else if(a[l]==a[r]){
				x=0;
				l++;
				r--;
			} 
			else{
				x=a[r]-a[l];
				y=b[r];
				z=1;
			}
		}
		else{
			if(a[l]>=a[r]){
				x=a[l]-a[r];
				y=b[l];
				z=0;
			}
			else if(a[l]==a[r]){
				x=0;
				l++;
				r--;
			} 
			else{
				x=a[r]-a[l];
				y=b[r];
				z=1;
			}
		}
	}
	cout<<cntz;
	return 0;
} 
