#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],g,h,he,o,oo,q;
bool cmp(long long b,long long c){
	return b<c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n%2==0){
		h=a[n/2];
	}
	else
	{
		h=a[n/2+1];
		oo=1;
	}
	//cout<<h;
	int ii=0;
	he=0;
	for(int j=1;j<=n/2;j++){
		int i=1;
		o=0;
		he=0;
		q=0;
		while(he<=m){
			if(oo=1){
				if(i<(n/2+1)-ii){
					o=1; 
				}
				if(i==(n/2+1)-ii){
					q=3;
				}
				if(i>(n/2+1)-ii){
					o=2; 
					break;
				}
			}
			else{
				if(i==(n/2)-ii){
					o=1; 
					break;
				}
			}
			
			he+=h-a[i];
			//cout<<a[i]<<" "<<he<<'\n';
			a[i]=h;
			i++;
		}
		if(q==3){
			for(int x=1;x<=n;x++){
				if(a[x]==h){
					g++;
				}
			}
			cout<<g;
			return 0;
		}
		else if(o==1){
			if(oo==1){
				h=a[n/2+1-j];
			}
			else h=a[n/2-j];
		}
		else{
			if(oo==1){
				h=a[n/2+1+j];
			}
			else h=a[n/2+j];
		}
		ii++;
	}
	return 0;
} 