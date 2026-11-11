#include<bits/stdc++.h>
using namespace std;
int n,m,bggg;
int a[200005];
void solv(int u) {
	int bgg=-1;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			int bg=a[j]&a[i];
			if(bgg<bg) {
				bgg=bg;
			}
		}
	}
	bggg=bgg;
	return ;
}
void sol(int u) {
	int bgg=-1,p,q;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			int bg=a[j]&a[i];
			if(bgg<bg) {
				bgg=bg;
				p=i;
				q=j;
			}
		}
	}
	a[p]=0,a[q]=0;
	if(u)bggg=bggg&bgg;
	else bggg=bgg;
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int biig=-1,lll=4,l=0,ll=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>biig)biig=a[i];
		if(a[i]>=lll)l=1;
		if(a[i]%2==0)ll=1;
	}
	if(m!=1) {
		if(m==2) {
			for(int i=1; i<m; i++) {
				solv(i);
			}
		} else if(m==3) {
			int bgg=-1;
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					for(int ji=j+1; ji<=n; ji++) {
						int bg=a[j]&a[i]&a[ji];
						if(bgg<bg) {
							bgg=bg;
						}
					}
				}
			}
			bggg=bgg;
		} else if(m==4) {
			int bgg=-1;
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					for(int ji=j+1; ji<=n; ji++) {
						for(int ij=ji+1; ij<=n; ij++) {
							int bg=a[j]&a[i]&a[ji]&a[ij];
							if(bgg<bg) {
								bgg=bg;
							}
						}
					}
				}
				bggg=bgg;
			}
		} else if(l&&ll) {
			for(int i=1; i<m; i++) {
				sol(i);
			}
		} else if(ll) {
			bggg=2;
		} else {
			bggg=biig;
		}
	} else {
		bggg=biig;
	}
	cout<<bggg;
	return 0;
}
