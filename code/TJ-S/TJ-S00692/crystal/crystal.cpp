#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],pr[N],pr2[N],c[N]; 
/*
@一条快乐的傻鱼 
我好想学dbc
可是我没钱买鼠标
只要luogu每人捐我0.1块我就能买了awa
立志成为最lieqi的pvp大蛇
并在此纪念pcl 感谢龙腾猫越的辛苦付出，人民会永远记住你！
我们会坚决同资本家 野心家奋斗到底！
敬礼！ 
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	c[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		pr[i]=pr[i-1]+c[i];
		//cout<<c[i]<<" "<<pr[i]<<"\n";
	}
	ll ans=1,num=0;
	int l=1,r=1;
	while(r<n){
		num-=pr[r]-pr[l-1];
		//cout<<"\n"<<num<<" "<<l<<" "<<r<<" "<<"\n";
		while(num+(r-l+1)*c[r+1]<=m&&r+1<=n){
			num+=(r-l+1)*c[r+1];
			r++;
			//cout<<num<<" "<<r<<"\n";
		}
		ans=max(ans,(ll)(r-l+1));
		l++;
	}
	cout<<ans;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
