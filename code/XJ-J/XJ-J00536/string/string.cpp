#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans;
char a[200010];
int cnt[200010];
char cx,cy;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		int x; cin>>x;
		char c; cin>>c;
		cnt[i]=x;
		a[i]=c;
	}
	int xcnt=0,ycnt=0;
	int x=0,y=n-1;
	while(x<=y) {
		if(xcnt!=0) {
			if(cx==a[y]) cnt[y]-=xcnt;
			else {
				if(xcnt>cnt[y]) {
					ans+=cnt[y];
					xcnt-=cnt[y];
					y--;
					continue;
				}
				ans+=xcnt;
				cnt[y]-=xcnt;
			}
			xcnt=0;
		}
		if(ycnt!=0) {
			if(cy==a[x]) cnt[x]-=ycnt;
			else {
				if(ycnt>cnt[x]) {
					ans+=cnt[x];
					ycnt-=cnt[x];
					y++;
					continue;
				}
				ans+=ycnt;
				cnt[x]-=ycnt;
			}
			ycnt=0;
		}
		
		
		if(cnt[x]!=cnt[y]) {
			if(a[x]==a[y]) {
				if(cnt[x]<cnt[y]) {
					ycnt=cnt[y]-cnt[x];
					cy=a[y];
				}
				else if(cnt[x]>cnt[y]) {
					xcnt=cnt[x]-cnt[y];
					cx=a[x];
				}
			}
			else if(cnt[x]<cnt[y]) {
				ans+=cnt[x];
				cy=a[y];
				ycnt=cnt[y]-cnt[x];
			}
			else if(cnt[x]>cnt[y]) {
				ans+=cnt[y];
				xcnt=cnt[x]-cnt[y];
				cx=a[x];
			}
		}
		else {
			if(a[x]!=a[y]) {
				ans+=cnt[y];
			}
		}
		x++; y--;
	}
	
	cout<<ans;
	
	
	return 0;
}