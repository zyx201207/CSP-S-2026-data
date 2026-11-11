#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5;
struct node{
	int num;
	char ch;
}a[maxn];
int n,len,ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
		len+=a[i].num;
	}
	int l=1,r=len;
	int lidx=1,ridx=n;
	int resl=a[1].num,resr=a[n].num;
	while(lidx<ridx){
		if(resl==resr){
			if(a[lidx].ch!=a[ridx].ch){
				ans+=resl;
			}
			l+=resl;
			r-=resr;
			lidx++;
			ridx--;
			resl=a[lidx].num;
			resr=a[ridx].num;
		} else if(resl<resr){
			if(a[lidx].ch!=a[ridx].ch){
				ans+=resl;
			}
			l+=resl;
			r-=resl;
			resr-=resl;
			lidx++;
			resl=a[lidx].num;
		} else {
			if(a[lidx].ch!=a[ridx].ch){
				ans+=resr;
			}
			l+=resr;
			r-=resr;
			resl-=resr;
			ridx--;
			resr=a[ridx].num;
		}
	}
	cout<<ans<<endl;
	return 0;
}