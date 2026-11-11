#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
using namespace std;
const int maxn=200005;
vector<int> s[26];
string t;
int n,m;
int ans;
struct node{
	int x;
	char c;
}a[maxn];
struct range{
	int l;
	int r;
};
vector<range> c[26];
int toint(char x){
	return (x-'a');
}
int findl(int ch,int x){
	int l=0,r=c[ch].size()-1;
	int tot=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(c[ch][mid].r>=x){
			tot=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return tot;
}
int findr(int ch,int x){
	int l=0,r=c[ch].size()-1;
	int tot=r;
	while(l<=r){
		int mid=(l+r)>>1;
		if(c[ch][mid].l<=x){
			tot=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return tot;
}
int calc(int l1,int r1,int l2,int r2){
	if(l2<=l1&&r1<=r2) return (r1-l1+1);
	if(l1<=l2&&r2<=r1) return (r2-l2+1);
	if(l1<=l2) return (r1-l2+1);
	return (r2-l1+1);
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	for(int i=1;i<=n;i++){
		c[toint(a[i].c)].push_back((range){m+1,m+a[i].x});
		m+=a[i].x;
	}
	if(m<=1e5){
		t=" ";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].x;j++) t+=a[i].c;
		}
		for(int i=1;i<=m/2;i++) if(t[i]!=t[m-i+1]) ans++;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<26;i++){
		s[i].resize(c[i].size());
		int l=c[i].size();
		if(l) s[i][0]=c[i][0].r-c[i][0].l+1;
		for(int j=1;j<l;j++) s[i][j]=s[i][j-1]+(c[i][j].r-c[i][j].l+1);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		int l=max(m-(sum+a[i].x)+1,(m+1)/2+1),r=m-(sum+1)+1;
		sum+=a[i].x;
		if(l>r) break;
		int x=findl(toint(a[i].c),l),y=findr(toint(a[i].c),r);
		if(c[toint(a[i].c)][y].r<l||c[toint(a[i].c)][x].l>r){
			ans+=(r-l+1);
			if(sum>=m/2) break;
			continue;
		}
		if(x>y) ans+=r-l+1;
		else if(x==y) ans+=max(r-l+1-calc(c[toint(a[i].c)][x].l,c[toint(a[i].c)][x].r,l,r),0ll);
		else if(x+1==y) ans+=max(r-l+1-calc(c[toint(a[i].c)][x].l,c[toint(a[i].c)][x].r,l,r)-calc(c[toint(a[i].c)][y].l,c[toint(a[i].c)][y].r,l,r),0ll);
		else{
			int w=r-l+1-calc(c[toint(a[i].c)][x].l,c[toint(a[i].c)][x].r,l,r)-calc(c[toint(a[i].c)][y].l,c[toint(a[i].c)][y].r,l,r);
			x++,y--;
			if(w>=0) w-=s[toint(a[i].c)][y]-s[toint(a[i].c)][x-1];
			ans+=max(w,0ll);
		}
		if(sum>=m/2) break;
	}
	cout<<ans;
	return 0;
}
