#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,cnt;
ll m;
ll ans,sum,Max,add,chazhi;
struct node{
	ll num,sum;
}a[N];
bool cmp(node x,node y){
	return x.num<y.num;
}
int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;a[i].sum=1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].num==a[cnt].num){
			a[cnt].sum++;
		}else{
			cnt++;
			a[cnt].num=a[i].num;
		}
	}
	if(m==0){
		for(int i=1;i<=cnt;i++){
			ans=max(ans,a[i].sum);
		}
		cout<<ans;
		return 0;
	}
	Max=cnt;
	sum=a[cnt].sum;
	for(int i=cnt-1;i>=1;i--){
		chazhi=a[Max].num-a[i].num;
		while(m<chazhi){
			sum-=a[Max].sum;
			m=(a[Max].num-a[Max-1].num)*sum+m;
			Max--;
			chazhi=a[Max].num-a[i].num;
		}
		while(m<a[i].sum*chazhi){
			ans=max(ans,sum+m/chazhi);
			sum-=a[Max].sum;
			m=(a[Max].num-a[Max-1].num)*sum+m;
			Max--;
			chazhi=a[Max].num-a[i].num;
		}
		sum+=a[i].sum;
		m-=a[i].sum*chazhi;
		ans=max(ans,sum);
	}
	cout<<ans;
	
	return 0;
}
