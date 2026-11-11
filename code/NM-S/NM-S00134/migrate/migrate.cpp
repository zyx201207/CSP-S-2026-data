#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool fun(ll a,ll b){
	return a<b;
} 
int main(){
	freopen("crystal.in","r",stdin);
/	freopen("crystal.out","w",stdout);
	int n = 0,m=0;
	vector<ll> a,e;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),fun);
	e.push_back(0); 
	for(int i=1;i<n;i++){
		e.push_back( e[i-1] + i * ( a[i] - a[i-1] ) );
	}
	long long mx = 0;
	ll index =0;
	for(ll i=n-1;i>=0;i--){
		if(m>=e[i]){
			mx = max(i+1,mx);
		}else{
			index = 0;
			for(ll j=0;j<i;j++){
				if(m>= e[i] - (index + a[i] - a[j]) ){
					mx = max(mx,i-j);
				}else{
					index += a[i]-a[j];
				}
			}
		} 
	}
	cout<<mx;
	return 0;
}
/*
给出一个数列Ai
让其中的元素至多增加m(自由分配)
使得相同的元素尽可能多
1 计算对于每一颗水晶
需要消耗多少能量才能让其他水晶与它能量值相同
递推计算：
e[i] =e[i-1]+i*(a[i]-a[i-1])
需要保证有序。
在不考虑能量的情况下
一定是以基础能量值更大的水晶作基准更优。
所以排序。从小到大。
然后从后向前遍历，遍历到第一个m>=e[i]的，
取i+1即为答案。（ 0 based ）
*/





/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool fun(ll a,ll b){
	return a<b;
} 
int main(){
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ll n = 0,m=0;
	vector<ll> a,e,b;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),fun);//排序
	b.push_back(1);
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			b.push_back(b[i-1]+1);
		}else{
			b.push_back(1);
		}
	}
//	for(int i=0;i<n;i++){
//		cout<<b[i]<<' ';	
//	}
//	cout<<endl;
	ll mx = 0;
	for(int i=n-1;i>0;i--){
		if(b[i+1]==1&&i!=n-1){
			int li = i - b[i] + 1;
			int lm = m;
			int cnt = 0;
			while(true){
				if(lm < a[li]-a[li-1]){
					break;
				}
				cnt++;
				lm -=a[li] -a[li-1];
			}
			mx = max(mx,b[i]+cnt);
		}else if(i==n-1){
			if(b[i]==1){
				continue;
			}else{
				int li = i - b[i] + 1;
				int lm = m;
				int cnt = 0;
				while(true){
					if(lm < a[li]-a[li-1]){
					break;
					}
					cnt++;
					lm -=a[li] -a[li-1];
				}
			mx = max(mx,b[i]+cnt);
			}
		}
	}
	cout<<mx;
	return 0;
}
Bi记录自己叠了多少个，cnt记录可以向前叠多少个 

*/

