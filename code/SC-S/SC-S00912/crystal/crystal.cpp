#include<bits/stdc++.h>
#define int long long
#define MAXN 100010
#define MAXM 2147483647
using namespace std;
int a[MAXN],sum,cnt,n,m,s,aa,num=1;
struct node{
	int cn,nu;
};
int sds(node x,node y){
	if(x.nu>y.nu)return 1;
	return 0;
}
node b[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=MAXM;
	a[n+1]=MAXM;a[n+2]=MAXM;a[n+3]=MAXM;a[n+4]=MAXM;a[n+5]=MAXM;
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			s++;
			if(i==j){
				cnt+=min(a[j+s]-a[i],a[i]-a[j-s]);
				aa=max(a[j+s]-a[i],a[i]-a[j-s]);
			}else{
					if(a[j+s-2]-a[i]==aa){
						cnt+=min(aa,a[i]-a[j-s-2]);
						if(j-s-2>0){
							aa=max(aa,a[i]-a[j-s-2]);
						}else{
							cnt-=min(aa,a[i]-a[j-s-2]);
							cnt+=a[j+s-1]-a[i];
						}
					}else{
						cnt+=min(aa,a[j+s-1]-a[i]);
						if(j+s-1<n){
							aa=max(aa,a[j+s-1]-a[i]);
						}
					}
			}
			num++;
			if(cnt>=m){
				break;
			}
		}
		b[i].cn=cnt;
		b[i].nu=num;
		num=0;
		cnt=0;
		s=0;
	}
	sort(b+1,b+1+n,sds);
	cout<<b[1].nu;
	return 0;
}