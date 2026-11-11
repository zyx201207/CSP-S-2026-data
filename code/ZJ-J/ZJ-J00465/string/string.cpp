#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int cnt;
	char l;
}a[200005],b[200005],c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int suml=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].l;suml+=a[i].cnt;
	}
	int cntl=0;
	for(int i=1;i<=n&&cntl<suml/2;i++){
		if(cntl+a[i].cnt>=suml/2) b[i].cnt=suml/2-cntl;
		else b[i].cnt=a[i].cnt;
		cntl+=b[i].cnt;b[i].l=a[i].l;
	}
	int cntr=0;
	for(int i=n;i>=1&&cntr<suml/2;i--){
		if(cntr+a[i].cnt>=suml/2) c[n+1-i].cnt=suml/2-cntr;
		else c[n+1-i].cnt=a[i].cnt;
		cntr+=c[n+1-i].cnt;c[n+1-i].l=a[i].l;
	}
	int l1=1,l2=1,cmpen=0,need=0;
	while(cmpen<suml/2){
		if(b[l1].cnt<c[l2].cnt){
			need+=b[l1].cnt*(b[l1].l!=c[l2].l);
			cmpen+=b[l1].cnt;
			c[l2].cnt-=b[l1].cnt;
			l1++;
		}else if(b[l1].cnt>c[l2].cnt){
			need+=c[l2].cnt*(b[l1].l!=c[l2].l);
			cmpen+=c[l2].cnt;
			b[l1].cnt-=c[l2].cnt;
			l2++;	
		}else{
			need+=(b[l1].l!=c[l2].l)*b[l1].cnt;
			cmpen+=b[l1].cnt;
			l1++;l2++;
		}
	}
	cout<<need;
	return 0;
}
