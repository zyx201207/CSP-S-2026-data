#include<bits/stdc++.h>//45pts+30pts=75pts 
//？编译器你的浮木呢  大小根堆什么的都根本用不了 你回家睡觉去吧 
using namespace std;
#define ll long long
ll i,j;
ll n,m;
const ll maxn=500005;
ll a[maxn];
//vector<priority_queue<ll> > pq;
/*
ccf你的浮木飘走了。暴力怎么你了
暴力怎么着你了？！？！？！？！？！？ 不对劲不会有pre吧
呜呼哀哉 式微式微
我靠真式微了。对面就是落地窗也是爽哉 观赏日落。我靠时间怎么过那么快。
那不就糟了旁边的人一直在打然而后面的我不会 呜呼哀哉
要是真的是75pts那就是2=差不多 那真的很不值得了。！！！！！！ 
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool teA=true;
	bool teB=true;
	ll xB=0;
	for(i=0;i<n;i++){
		cin>>a[i];
//		pq.push(a[i]);
		if(a[i]!=i+1)teA=false;
		if(i==1)xB=a[i]-a[i-1];
		else if(i>1){
			if(a[i]-a[i-1]!=xB)teB=false;
		}
	}
	if(teA){
		ll now=0;
		ll ans=1;
		for(i=1;i<n;i++){
			ans++;
			now+=i;
			if(now>m){
				cout<<ans-1;
				return 0;
			}
			else if(now==m){
				cout<<ans;
				return 0;
			}
		}
	}
	if(teB){
		ll now=0;
		ll ans=1;
		for(i=1;i<n;i++){
			ans++;
			now+=i*xB;
//			cout<<now<<endl;
			if(now>m){
				cout<<ans-1;
				return 0;
			} 
			else if(now==m){
				cout<<ans;
				return 0;
			} 
		}
	}
	if(m==0){
		cout<<1<<endl;
//		ll ans=0;
//		ll anss=1;
//		ll nown=pq.top();
//		pq.pop(); 
//		while(!pq.empty()){
//			if(pq.top()!=nown){
//				ans=max(ans,anss);
//				anss=1;
//				nown=pq.top();
//				pq.pop(); 
//				continue;
//			}
//			else anss++;
//		}
//		ans=max(anss,ans);
		return 0;
	}
	sort(a,a+n);
	ll ans=-1e18;//保底ans一定=1，也就是不操作 
	for(i=n-1;i>=0;i--){//倒着进行循环。bre我这都砍树了还TLE ccf你浮木飘走了 
		ll now=0,anss=0; 
		if(i>0&&a[i]-a[i-1]>m)continue;//无法计算,第一个已经超过了 
		if(i+1<=ans){
//		    cout<<"qwq"<<i<<endl;
			break;//剩下的不用看了 已经绝对不可能再超过ans了 
		}
		if(i+1==1){
			break;//就剩下1了还循环你滚木呢 
		} 
		for(j=i;j>=0;j--){
			if(anss+j+1<=ans){
//			    cout<<"qqq"<<endl;
				break;//即使剩下的全部都可以用也超过不了了 
			}
			ll x=a[i]-a[j];
			now+=x;
			anss++;
			if(now>m){//要是当前已经超额就直接结束，记录anss 
				anss--;
				break;
			}
			else if(now==m)break;//不用继续加了 
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}
/*
将序列从大到小进行排序，然后从最大的那个开始向下遍历
now用来计算当前花费，要是花费>=m那么记录答案然后跳过发和  
*/ 
