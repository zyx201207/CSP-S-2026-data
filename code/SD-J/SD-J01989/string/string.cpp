#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
struct node{
	int shuliang;
	char x;
}a[200010];
struct nodee{
	int shuliang;
	char x;
	int next;
}b[1000010];
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++) cin >>a[i].shuliang>>a[i].x;
	int len=0,t=0;
	b[0].next=-1;
	for(int i=1,j=n;;){
		if(i==j){
			b[++len].shuliang=a[i].shuliang;
			b[len].x=a[i].x;
			b[len].next=b[t].next;
			b[t].next=len;
			break;
		}
		if(a[i].shuliang<a[j].shuliang){
			a[j].shuliang-=a[i].shuliang;
			b[++len].shuliang=a[i].shuliang;
			b[len].x=a[i].x;
			b[len].next=b[t].next;
			b[t].next=len;
			++i;
		}else if(a[i].shuliang>a[j].shuliang){
			a[i].shuliang-=a[j].shuliang;
			b[++len].shuliang=a[j].shuliang;
			b[len].x=a[j].x;
			b[len].next=b[t].next;
			b[t].next=len;
			--j;
			++t;
		}else{
			b[++len].shuliang=a[i].shuliang;
			b[len].x=a[i].x;
			b[len].next=b[t].next;
			b[t].next=len;
			++i;
			b[++len].shuliang=a[j].shuliang;
			b[len].x=a[j].x;
			b[len].next=b[t].next;
			b[t].next=len;
			--j;
			++t;
		}
	}
	int alen=0;
	int ans=0;
	for(int i=1;i!=-1;i=b[i].next){
		a[++alen].shuliang=b[i].shuliang;
		a[alen].x=b[i].x;
	}
	for(int i=1;i<=alen;i++) if(a[i].x!=a[len-i+1].x) ans+=b[i].shuliang;
	cout <<ans;
	
	return 0;
}
