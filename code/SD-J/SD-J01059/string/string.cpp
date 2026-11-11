#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
struct node{
	int a;
	char c;
	ll l,r;
	int len;
} d[maxn];
int n;
ll len,ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int now=1;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].c;
		len+=(ll)(d[i].a);
		d[i].l=len-(ll)(d[i].a)+1ll;
		d[i].r=len;
		d[i].len=d[i].r-d[i].l+1;
	}
	int l=1,r=n;
	while(l<=r){
		int mov=min(d[l].len,d[r].len); 
		if(d[l].c!=d[r].c){//需要修改 
			ans+=mov;
		}
		if(mov==d[l].len&&mov==d[r].len){//移动部分一样长 
			l++,r--;//一起向中间移 
		}
		else if(mov==d[l].len&&mov!=d[r].len){//左指针右移的值较小 
			l++;//左指针向右移 
			d[r].len-=mov;//与左指针移动相同的数，但还在d[r]的区间里 
		}
		else if(mov==d[r].len&&mov!=d[l].len){//右指针左移的值较小 
			r--; //扫左边的区间 
			d[l].len-=mov;//向右移 
		}
	}
	cout<<ans;
	return 0;
}

