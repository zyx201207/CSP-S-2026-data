#include<bits/stdc++.h>
#define int long long
using namespace std;
struct asdfg{
	int m;char c;
} a[200005];
struct asdfh{
	int m;int k;
} p1,p2;
int n,all,ans,now;
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		all+=a[i].m;
	}
	for(int i=0;i<n;i++){
		now+=a[i].m;
		if(now+a[i+1].m>=all/2){
			p1.m=i+1,p1.k=all/2-now;
			break;
		}
	}
	if(all%2==0){
		if(a[p1.m].m>p1.k) p2.m=p1.m,p2.k=a[p1.m].m-p1.k;
		else p2.m=p1.m+1,p2.k=a[p1.m+1].m;
	}
	else{
		if(a[p1.m].m>=p1.k+2) p2.m=p1.m,p2.k=a[p1.m].m-1-p1.k;
		else if(a[p1.m].m>p1.k) p2.m=p1.m+1,p2.k=a[p1.m+1].m;
		else p2.m=p1.m+1,p2.k=a[p1.m+1].m-1;
	}
	//cout<<p1.m<<p1.k<<p2.m<<p2.k;
	while(p1.m!=1||p1.k!=0){
		int x=min(p1.k,p2.k);
		if(a[p1.m].c!=a[p2.m].c) ans+=x;
		p1.k-=x,p2.k-=x;
		if(p1.k==0&&p1.m!=1) p1.m=p1.m-1,p1.k=a[p1.m].m;
		if(p2.k==0&&p2.m!=n) p2.m=p2.m+1,p2.k=a[p2.m].m;
	}
	cout<<ans;
	return 0;
}

