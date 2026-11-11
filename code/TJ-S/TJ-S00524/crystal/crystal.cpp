#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum;
int a[500005],maxn=1,pre,d,cnt;
deque<int>q;
void Insert(int i){
	d+=cnt*(a[i]-pre);
	cnt++;
	q.push_back(i);
	while(q.size()&&d>m){
		d-=(a[i]-a[q.front()]);
		q.pop_front();
		cnt--;
	}maxn=max(maxn,cnt);
	//cout<<cnt<<' ';
	return;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+1+n);
	pre=a[1];
	for(int i=1;i<=n;i++){
		Insert(i);
		pre=a[i];
	}cout<<maxn;
	
	return 0;
} 
