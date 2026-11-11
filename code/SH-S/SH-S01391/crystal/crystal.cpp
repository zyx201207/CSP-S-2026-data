#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[500010];
int check(int n,ll cnt){
	return a[n]<=cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int num=0,cnt=0;
		for(int j=i;j>0;j--){
			num++;
			cnt+=a[i]-a[j];
			//cout<<a[i]<<'-'<<a[j]<<endl;//---------------
			if(cnt>m){
				num--;
				break;
			}
		}
		//cout<<"---"<<ans<<'-'<<num<<endl;//--------------
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
