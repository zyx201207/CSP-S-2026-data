#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],v,ans=1,tmp;
bool flag=true;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//feizhengjie
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		a[i]=a[i+1]-a[i];
		if(i==1){
			tmp=a[i];
		}
		else{
			if(flag && tmp!=a[i]){
				flag=false;
			}
		}//flag 判断是否为等差数列
	}//chafen
	if(n<=5e5 && flag){
		for(int i=n-1;i>=0;i--){//间隔数
			if(2*m/((i+1)*i)>=tmp){
				cout<<i+1;
				return 0;
			}
		}
		return 0;
	}
	//cheat 16-18
	int l=1,r=n-1;
	ll cnt,ans1=1;
	while(l<=r){
		//mid=(l+r)>>1;
		cnt=m;
		ans1=1;
		for(int i=l;i<n;i++){
			v=(i-l+1)*a[i];
			cout<<l<<" "<<cnt<<" "<<v<<"\n";
			if(cnt>=v){
				ans1++;
				cnt-=v;
			}
			else{
				ans=max(ans1,ans);
				break;
			}
		}
		l++;
	}
	/*
	O(n^2) ~ 45
	*/
	cout<<ans;
	return 0;
}