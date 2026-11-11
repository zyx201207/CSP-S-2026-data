#include <bits/stdc++.h>
using namespace std;
int GM,T,x,y,sl,n,k,i;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>GM>>T;
	while(T--){
		cin>>n>>k;
//		for(i=1;i<n;i++) cin>>x>>y;
		if(GM==13||GM==14){
			int sl;
			if(n%4==3){
				sl=(n+1)/4;
				k-=2;
				if(k<sl)
					if(k==sl-1) sl=1;
					else sl=sl-k/2;
				else if(k>=n-2) sl=0;
				else sl=1;
			}else{
				sl=(n-1)/4;
				k-=2;
				if(k<=sl) sl=sl-k/2;
				else if(k>=n-2) sl=0;
				else sl=1;
			}
			if(sl==0) cout<<sl<<"\n";
			else cout<<sl/2+1<<"\n";
		}
	}
	return 0;
}
/*
pts=10
ÆÀ²â»ú±£ÓÓÎÒ 
*/
