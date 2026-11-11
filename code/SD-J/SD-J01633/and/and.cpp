#include<bits/stdc++.h>
using namespace std;
int maxn=INT_MIN,m,n;
int a[200001];
void dfs(int xds,int id,int yu,int iid){
	if(id>=m){//选数数量达到m 
		maxn=max(yu,maxn);
		return;
	}
	if(iid>n){//目前选的下标超过n 
		return;
	}
	dfs(a[iid+1],id+1,yu&a[iid+1],iid+1);//选的话那就选下一个坐标的数，选数数量++,与上下一个数，下标++ 
	dfs(a[iid],id,yu,iid+1);//不选的话就不+1，选数数量也不加，不与数，下标++找下一个 
}
bool check(int x){
	vector<int> aa;
	aa.push_back(11111);
	while(x>=1){
		aa.push_back(x%2);
		x/=2;
	}
	int ccsp=0;
	for(int i=1;i<=aa.size();i++){
		if(aa[i]==1){
			ccsp++;
		}
	}
	if(ccsp==aa.size()-1){
		return 1;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){//只选一个数相当于整个数组最大值 
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]); 
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){//选n个数就直接所有数互相与 
		int ans=a[1];
		for(int j=2;j<=n;j++){
			ans&=a[j];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){//要么1~n-1要么2~n 
		int ans=a[1];
		for(int j=2;j<=n-1;j++){
			ans&=a[j];
		}
		int cnt=a[2];
		for(int j=3;j<=n;j++){
			cnt&=a[j];
		}
		cout<<max(cnt,ans);
		return 0;
	}
	int yye=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i-1){
			yye++;
		}
	}
	int ye=0;
	for(int i=1;i<=n;i++){
		if(check(a[i])){//是2的某次方-1 
			ye++;
		}
	}
	if(ye==n||yye==n){//特殊性质A，最小的数都是后m个数 等于1或n的特殊情况已经判断 
		sort(a+1,a+n+1);
		int cnt=a[n-m+1];
		for(int i=n-m+2;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],1,a[i],i);//从a[i]开始选数，选数数量为1，当前与的数为当前数，下标为i 
	}
	cout<<maxn;
	return 0;
} 
