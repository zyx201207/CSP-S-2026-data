#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n;
struct duan{
	char c;
	int l;
	int r;
}d[N];
int ll=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	int nr=0;
	for(int i=1;i<=n;i++){
		int len;
		char c;
		cin>>len>>c;
		ll+=len;
		int l=nr+1;
		int r=l+len-1;
//		cout<<l<<" "<<r<<'\n';
		nr=r;
		if(c!=d[cnt].c||cnt==0){
			cnt++;
			d[cnt].l=l;
			d[cnt].r=r;
			d[cnt].c=c;
		}else{
			d[cnt].r=r;
		}
	}
	int mid=ll/2;
	mid+=(ll%2);
	int mm=0;
	for(int i=1;i<=cnt;i++){
		if(d[i].l<=mid&&mid<=d[i].r){
			mm=i;
		}
		if(d[i].l<=mid&&mid+1<=d[i].r){
			duan h;
			mm=i;
			h.l=mid+1;
			h.r=d[i].r; 
			h.c=d[i].c;
			d[i].r=mid-(ll%2);
			for(int k=cnt+1;k>=i+2;k--){
				d[k]=d[k-1];
			}
			cnt++;
			d[i+1]=h;
			break;
		}
	}
//	cout<<mid<<'\n';
	for(int i=mm+1;i<=cnt;i++){
//		cout<<d[i].l<<" "<<d[i].r<<'\n';
		d[i].l=ll-d[i].l+1;
		d[i].r=ll-d[i].r+1;
//		cout<<d[i].l<<" "<<d[i].r<<'\n';
		swap(d[i].l,d[i].r);
	}
	int ni=0;
	int nk=1;
	int np=cnt;
	int ans=0;
	mid-=(ll%2);
	while(ni<=mid&&np>mm&&nk<=mm){
//		cout<<d[nk].r<<" "<<d[np].r<<" "<<ni<<'\n';
		if(d[nk].c==d[np].c){
			ans+=0;
			if(d[np].r<=d[nk].r){
				ni=d[np].r;
				np--;
			}else{
				ni=d[nk].r;
				nk++;
			}
		}else{
			ans+=min(d[np].r,d[nk].r)-ni;
			if(d[np].r<=d[nk].r){
				ni=d[np].r;
				np--;
			}else{
				ni=d[nk].r;
				nk++;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
