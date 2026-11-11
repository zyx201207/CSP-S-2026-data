#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500005];
int c[500005],he[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<" ";
		he[i]=he[i-1]+a[i];
		//cout<<he[i]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		c[i]=a[i]*i-he[i];
		//if(c[i]!=c[i-1])cout<<i-1<<" ";
	}
	//cout<<endl;
	int ans=upper_bound(c+1,c+1+n,m)-(c+1);
	/*if(c[ans]<m){
		int sum=0,cnt=0;
		for(int i=ans;;i++){
			if(c[i]!=c[ans]){
				sum=c[i];
				cnt=i;
				break;
			}
		}
		cout<<sum<<endl;
		int i=1;
		while(1){
			if(sum<=m){
				cout<<cnt-i-1;
				return 0;
			}
			sum-=(a[cnt]-a[i]);
			cout<<sum<<" ";
			i++;
		}
	}*/
	cout<<ans;
	
	return 0;
}
//Oct31==Dec25?
//我常常追忆过去。

//走到这里 不管结果如何 你已经赢了
//全力以赴 不留遗憾 
//怎么死活过不了最后一个大洋里啊。已经调了半个多小时了。
//又返回来看还是调不出来 啊啊啊 
//这样一个半假不假的贪心能得？分呢 
