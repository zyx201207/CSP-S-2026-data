#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,O=1e8;
int n;
//int a[N];
//char c[N];
struct node{
	long long l,r;
	char c;
};
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<node> q(n+1);
	int j=0;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		q[i].l=j+1;
		j+=a;
		q[i].r=j;
		q[i].c=c;
	}
//	cout<<j<<"\n";
	if(j/2<=O){
		int ans=0;
		string s="";
		for(int i=1;i<=n;i++){
			for(int p=q[i].l;p<=q[i].r;p++){
				s+=q[i].c;
			}
		}
		for(int i=0;i<=j/2;i++){
			if(s[i]!=s[j-i-1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
//	cout<<"\n";
	
	int x=1,y=n;
	int ans=0;
	int lr=j+1;
	while(x<y){
//		printf("%d %d:\n",x,y);
		int nl=j+1-q[x].r,nr=j+1-q[x].l;
//		printf("  %d %d  %d %d\n",nl,nr,q[y].l,q[y].r);
		int cl=max(nl,q[y].l),cr=lr;
		lr=cl;
//		printf("   %d ~ %d\n",cl,cr);
		if(q[x].c!=q[y].c){
			ans+=cr-cl;
//		printf("     !:%d\n",ans);
		}
		if(q[x].r>j/2){
			y--;
		}else if(q[y].l<=j/2){
			x++;
		}else if(j/2-q[x].r+1<q[y].l-j/2){
			y--;
		}else{
			x++;
		}
	}
	cout<<ans;
	return 0;
}