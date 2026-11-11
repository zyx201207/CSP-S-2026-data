#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
int ans;
int l,r;
int cntl,cntr;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1,r=n;
	while(true){
		int x=a[l],y=a[r];
//		cout<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<cntl<<' '<<cntr<<' '<<ans<<endl;
		if(l-r>1)break;
//		if(l-r==1){
//			if(abs(cntl-cntr)>a[l]){
//				if(cntl>cntr&&c[l-1]!=c[l])ans+=a[l];
//				else if(cntl>cntl&&c[l+1]!=c[l])ans+=a[l];
//			}
//			else{
//				if(cntl>cntr&&c[l-1]!=c[l])ans+=abs(cntl-cntr);
//				else if(cntl>cntl&&c[l+1]!=c[l])ans+=abs(cntl-cntr);
//			}
//			break;
//		}
		if(l==1&&r==n){
			if(a[l]>a[r]){
				if(c[l-1]!=c[r])ans+=cntr+y-max(cntr,cntl-a[l-1]);
			}
			else{
				if(c[l]!=c[r+1])ans+=cntl+x-max(cntl,cntl-a[r+1]);
			}
			cntr+=y;
			r--;
			cntl+=x;
			l++;
			continue;
		}
		if(cntr<cntl){
			if(c[l-1]!=c[r])ans+=min(cntr+y,cntl)-max(cntr,cntl-a[l-1]);
			cntr+=y;
			r--;
		}
		else{
			if(c[l]!=c[r+1])ans+=min(cntl+x,cntr)-max(cntl,cntr-a[r+1]);
			cntl+=x;
			l++;
		}
	}
//	if(l-r==1){
//			if(abs(cntl-cntr)>a[l]){
//				if(cntl>cntr&&c[l-1]!=c[l])ans+=a[l];
//				else if(cntl>cntl&&c[l+1]!=c[l])ans+=a[l];
//			}
//			else{
//				if(cntl>cntr&&c[l-1]!=c[l])ans+=abs(cntl-cntr);
//				else if(cntl>cntl&&c[l+1]!=c[l])ans+=abs(cntl-cntr);
//			}
//			//break;
//		}
	cout<<ans;
	return 0;
}
/*
5
87 e
28 v
33 q
13 y
2 b
*/
/*
5
7 o
73 a
82 a
26 q
20 t
*/
/*
8
81 m
58 g
15 e
40 u
51 p
5 t
76 g
56 d
*/
