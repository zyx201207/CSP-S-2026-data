#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int b[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int x=0;x<n;x++) cin>>a[x];
	int l=0;
	bool c[300100]={false};
	int ans[300100]={0};
	for(int x=0;x<n;x++){
		for(int y=x-1;y<n;y++){
			bool f=false;
			for(int z=0;z<l;z++){
				if(a[y]==b[z]){
					int r=l;
					for(int xx=z;xx<r;xx++){
						b[xx]=0;
						l--;
					}
					b[l]=a[y];
					f=true;
					break;
				}
			}
			if(f!=true){
				b[l-1]=a[y];
				l++;
			}
			//实在做不出来 
		}
		for(int y=0;y<n;y++) c[b[y]-1]=true;
		for(int y=0;y<m;y++){
			if(c[y]==true) ans[y]++;
		}
		for(int y=0;y<m;y++) c[y]=false;
	}
	bool fir=true;
	for(int x=0;x<m;x++){
		if(fir==true) cout<<ans[x];
		else cout<<" "<<ans[x];
		fir=false;
	}
	return 0;
}

