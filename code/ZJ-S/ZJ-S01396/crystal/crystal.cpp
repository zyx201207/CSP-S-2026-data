#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],x;
int n,ma,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) x++;
		else b[i-x]=i;
	}
	for(int i=1;i<=n-x;i++){
		int mid=b[i];
		long long mm=m,y=a[mid];
		int xx=1,l,r,ll=0,rr=0;
		if(mid-1>=1) l=mid-1;
		else l=1,ll=1;
		if(mid+1<=n) r=mid+1;
		else r=n,rr=1;
		while(mm>=0){
			long long u=y-a[l],v=(a[r]-y)*xx;
			if(ll==1&&rr==1) break;
			else if(ll==1){
				if(mm>=v){
					mm-=v;
					xx++;
					y=a[r];
					if(r+1<=n) r++;
					else rr=1;
				}else break;
			}else if(rr==1){
				if(mm>=u){
					mm-=u;
					xx++;
					if(l-1>=1) l--;
					else ll=1;
				}else break;
			}else if(mm>=min(u,v)){
				if(u<=v){
					mm-=u;
					xx++;
					if(l-1>=1) l--;
					else ll=1;
				}else{
					mm-=v;
					xx++;
					y=a[r];
					if(r+1<=n) r++;
					else rr=1;
				}
			}else break;
		}
		ma=max(ma,xx);
	}
	cout<<ma;
	return 0;
}
