#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e5+7;
int n;
long long sum=0,ans;
struct node{
	long long x,y;
	char s;
}a[N];
bool check(int l1,int r1,int l2,int r2){
	return (l2>=l1)&&(r2<=r1);
}
bool check1(int l1,int r1,int l2,int r2){
	return (l2<=l1)&&(r2>=r1);
}
bool check2(int l1,int r1,int l2,int r2){
	return (l2<=l1)&&(r2<=r1);
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	a[1].x=1;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x>>a[i].s;
		sum+=x;
		a[i].y=sum;
		a[i+1].x=sum+1;
	}
	int num=sum;
	for (int i=1;i<=n;i++){
		if (num<=0){
			break;
		}
		int l=sum-a[i].y+1,r=sum-a[i].x+1,cnt=a[i].y-a[i].x+1;
		if (num<cnt*2){
			l=a[i].y;
		}
		num-=cnt*2;
		for (int j=n;j>=1;j--){
			if (a[i].s!=a[j].s)continue;
			if(a[j].y<l||a[j].x>r) break;
			if (check(l,r,a[j].x,a[j].y)){
				cnt-=a[j].y-a[j].x+1;
			}
			else if (check1(l,r,a[j].x,a[j].y)){
				cnt=0;
			}
			else if (check2(l,r,a[j].x,a[j].y)){
				cnt-=a[j].y-l+1;
			}
			else {
				cnt-=r-a[j].x+1;
			}
		}
		ans+=cnt;
	}
	cout<<ans;
}
