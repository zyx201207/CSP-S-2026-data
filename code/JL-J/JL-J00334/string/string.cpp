#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,x,ans;
struct node{
	long long l,r;
	char x;
}seg[N];
long long l=1,r,cnt,xl,xr,yl,yr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		char c;																																
		cin>>c;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		r=l+x-1;
		seg[++cnt].l=l,seg[cnt].r=r,seg[cnt].x=c;
		l=r+1;
	}
	l=1,r=cnt;
	xl=seg[1].l,xr=seg[1].r,yl=seg[r].l,yr=seg[r].r;
	while(l<=r){
		long long lenl=xr-xl+1,lenr=yr-yl+1;
		if(seg[l].x!=seg[r].x) ans+=min(lenl,lenr);
		if(lenl<lenr){
			yr-=lenl;
			l++;
			xl=seg[l].l,xr=seg[l].r;
		}else if(lenl==lenr){
			l++,r--;
			xl=seg[l].l,xr=seg[l].r,yl=seg[r].l,yr=seg[r].r;
		}else{
			xl+=lenr;
			r--;
			yl=seg[r].l,yr=seg[r].r;
		}
	}
	cout<<ans;
	return 0;
}																										
