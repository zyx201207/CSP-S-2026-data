#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int ges;
	char zimu;
}a[N];
int n,idl=1,idr;
long long l=0,mid,r,last,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	idr=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ges>>a[i].zimu;
		r+=a[i].ges;
	}
	mid=(1+r)/(2*1ll);
	int bc=0;
	while((l+a[idl].ges)<=mid){
//		cout<<l<<" "<<r<<"\n";
//		cout<<idl<<" "<<idr<<"\n";
		l+=a[idl].ges;
		r=r-a[idl].ges;
		bc=a[idl].ges;
		if(idl==idr) break;
		if(last>0){
			if(bc>=last){
				if(a[idl].zimu!=a[idr].zimu){
					ans+=last;
				}
				bc-=last;
			}else{
				while(bc<last){
					bc+=a[++idl].ges;
					if(a[idl].zimu!=a[idr].zimu){
						ans+=a[idl].ges;
					}
				}
				bc-=last;
			}
		}else if(last<0){
			bc-=last;
		}
		if(bc>a[idr].ges){
			if(a[idl].zimu!=a[idr].zimu){
				ans+=a[idr].ges;
			}
		}else if(bc<=a[idr].ges){
			if(a[idl].zimu!=a[idr].zimu){
				ans+=bc;
			}
		}
		last=bc-a[idr].ges;
		if(bc>a[idr].ges){
			idr--;
		}
		idl++;
	}
	if((l+a[idl].ges)!=mid){
		while(l<mid){
			if(a[l].zimu!=a[r].zimu){
				ans++;
			} 
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
