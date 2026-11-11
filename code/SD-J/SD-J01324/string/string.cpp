#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
	int l,r,cnt;
	char c;
}a[N];
int n,m,l=1,sum,len;
bool vis[N];
bool checkl(int x,int l){
	if(a[x].r>=l)return 1;
	else return 0;
}
bool checkr(int x,int r){
	if(a[x].l<=r)return 1;
	else return 0;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].cnt>>a[i].c;
		a[i].l=l;
		len+=a[i].cnt;
		a[i].r=l+a[i].cnt-1;
		l=a[i].r+1;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])break;
		int L=0,R=0;
		int l=i,r=n;
		vis[i]=1;
		while(l<r){
			int mid=l+r>>1;
			if(checkl(mid,len-a[i].r+1))r=mid;
			else l=mid+1;
		}
		L=l;
		l=i,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(checkr(mid,len-a[i].l+1))l=mid;
			else r=mid-1;
		}
		R=l;
		for(int j=L+1;j<=R;++j){
			if(a[j].c!=a[i].c){
				sum+=a[j].r-a[j].l+1;
			
			}
			vis[j]=1;
		}
		if(a[L].c!=a[i].c){
			sum+=a[L].r-(len-a[i].r);
		}
		if(a[L].l==len-a[i].r+1)vis[L]=1;
		a[L].r=len-a[i].r;
//		cout<<i<<'\n';
	}
	
	cout<<sum;
	return 0;
} 

//ºì»Æ»ÆÂÌ 
