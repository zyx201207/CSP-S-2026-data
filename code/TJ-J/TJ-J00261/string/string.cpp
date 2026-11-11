#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	long long nu;
	char c;
};
int n,l,r,ans;
st a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].nu>>a[i].c;
		//cout<<a[i].c<<' ';
	}r=1;
	l=n;
	while(r<l){
		//cout<<a[r][1]<<' '<<a[r][2]<<' ';
		if(a[r].nu>a[l].nu and a[r].c==a[l].c){
			a[r].nu-=a[l].nu;
			l--;
		}else if(a[r].nu==a[l].nu and a[r].c==a[l].c){
			r++;
			l--;
		}else if(a[r].nu<a[l].nu and a[r].c==a[l].c){
			a[l].nu-=a[r].nu;
			r++;
		}else if(a[r].nu>a[l].nu and a[r].c!=a[l].c){
			ans+=a[l].nu;
			a[r].nu-=a[l].nu;
			l--;
		}else if(a[r].nu==a[l].nu and a[r].c!=a[l].c){
			ans+=a[l].nu;
			r++;
			l--;
		}else if(a[r].nu<a[l].nu and a[r].c!=a[l].c){
			ans+=a[r].nu;
			a[l].nu-=a[r].nu;
			r++;
		}
	}cout<<ans;
	return 0;
}
