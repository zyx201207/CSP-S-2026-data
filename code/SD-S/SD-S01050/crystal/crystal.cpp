#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct cry{
	long long a;
	long long d;
	int o;
};
cry p[510000];
bool cmp(cry x,cry y){
	return x.a<y.a;
}
bool cmp1(cry x,cry y){
	if(x.d!=y.d) return x.d<y.d;
	else x.a<y.a;
}
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> p[i].a;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<n;i++){
		p[i].d=p[i+1].a-p[i].a;
		p[i].o=i;
	}
	p[n].o=n;
	sort(p+1,p+n,cmp1);
	long long i=1;
	while(m>0){
		if(m>=p[i].d&&p[n-1].d!=0){
			m-=p[i].d;
			p[i].a+=p[i].d;
			ans++;
			int j=1;
			for(;j<=n;j++){
				if(p[j].o==p[i].o-1){
					p[j].d+=p[i].d;
					break;
				}
			}
			for(int k=j;k<=n;k++){
				if(p[k].d>=p[k-1].d&&(p[k].d<=p[k+1].d||k==n)){
					for(int l=n;l>k;l--){
						p[l+1].a=p[l].a;
						p[l+1].d=p[l].d;
						p[l+1].o=p[l].o;
					}
					p[k+1].a=p[k].a;
					p[k+1].d=p[k].d;
					p[k+1].o=p[k].o;
				}
			}
			p[i].d=0;
		}
		else break;
		i++;
	}
	cout << ans;
	return 0;
}

