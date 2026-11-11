#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int maxx=-1e18;
int qzh[N];
int cha[N];
int jia[N];
int l,r,total,siz;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		qzh[i]=qzh[i-1]+cha[i];
	}
	for(int i=2;i<=n;i++){
		jia[i]=jia[i-1]+cha[i]*(i-1);
	}
	l=1;
	r=1;
	maxx=1;
	total=0;
	siz=1;
	while(r<=n&&l<=r){
		if(total<=m){
			r++;
			total+=cha[r]*siz;
			siz++;
		}else{
			total-=(qzh[r]-qzh[l]);
			l++;
			siz--;
		}
		maxx=max(maxx,siz-1);
	}
	cout<<maxx;
}
