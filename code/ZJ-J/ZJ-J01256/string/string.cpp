#include<bits/stdc++.h>
//#define baoli
#define IO freopen("string.in","r",stdin);freopen("string.out","w",stdout);
typedef long long ll;
using namespace std;
typedef struct node{
	char c;
	ll l,r;
}node;
int n;
node A[200010];
ll ans=0;
string s;
signed main(){
	IO;
#ifdef baoli
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int len;
		char c;
		cin>>len>>c;
		for(int j=1;j<=len;j++)
			s+=c;
	}
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-1-i])
			ans++;
	}
	cout<<ans;
#else
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int len;
		char c;
		scanf("%d %c",&len,&c);
		A[i].l=A[i-1].r+1,A[i].r=A[i-1].r+len;
		A[i].c=c;
	}
	int p=n;
	for(int i=1;A[i].l<=(A[n].r+1)/2;i++){
		ll l=A[n].r-A[i].r+1,r=A[n].r-A[i].l+1;
		l=max(l,(A[n].r+1)/2);
		r=max(r,(A[n].r+1)/2);
		ll al=min(A[i].l,(A[n].r+1)/2);
		ll ar=min(A[i].r,(A[n].r+1)/2);
//		l=min(l,(A[n].r+1)/2);
//		r=min(r,(A[n].r+1)/2);
		while(A[p].r>al){
			ll tl=max(A[p].l,l),tr=min(A[p].r,r);
	//		printf("p: %d    l:%d  r:%d   tl:%d  tr:%d\n",p,l,r,tl,tr);
			if(A[p].c!=A[i].c)ans+=tr-tl+1;
			if(A[p].l<l)break;
			p--;
		}
	}
	printf("%lld",max(0ll,ans));
#endif
	return 0;
}