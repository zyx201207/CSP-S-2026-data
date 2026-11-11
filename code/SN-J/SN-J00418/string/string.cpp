#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,xx,yy;
struct node {
	int x;
	char a;
} v[2000001];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>v[i].x>>v[i].a;
	}
	xx=1;
	yy=v[n].x;
	for(int i=1,j=n; i<=j; i++,j--) {
		if(xx==1 && yy==v[j].x) {
			if(v[i].x==v[j].x) {
				if(v[i].a==v[j].a) {
					yy=v[j-1].x;
				} else {
					yy=v[j-1].x;
					ans+=v[i].x;
				}
			} else {
				if(v[i].x>v[j].x) {

					if(v[i].a==v[j].a) {
						xx=v[j].x+1;
						yy=v[j-1].x;
						i--;
					} else {
						xx=v[j].x+1;
						yy=v[j-1].x;
						i--;
						ans+=v[j].x;
					}
				} else {

					if(v[i].a==v[j].a) {
						xx=1;
						yy=v[j].x-v[i].x;
						j++;
					} else {
						xx=1;
						yy=v[j].x-v[i].x;
						j++;
						ans+=v[i].x;
					}
				}
			}
		} else {
			if(v[i].x-xx+1>yy) {
				if(v[i].a==v[j].a) {
					xx+=v[j].x;
					yy=v[j-1].x;
					i--;
				} else {
					xx+=v[j].x;
					ans+=yy;
					yy=v[j-1].x;
					i--;
				}

			} else if(v[i].x-xx+1<yy) {

				if(v[i].a==v[j].a) {
					yy-=v[i].x-xx+1;
					j++;
					xx=1;
				}else{
					yy-=v[i].x-xx+1;
					j++;
					ans+=v[i].x-xx+1;
					xx=1;
				}
				
			} else {
				if(v[i].a==v[j].a){
					xx=1;
					yy=v[j-1].x;
				}else{
					xx=1;
					ans+=yy;
					yy=v[j-1].x;
				}
				
			}
		}
	}
	cout<<ans;
	return 0;
}
