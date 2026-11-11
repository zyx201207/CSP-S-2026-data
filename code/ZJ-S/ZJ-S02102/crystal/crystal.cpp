#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int a[N],ans[N];
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag1,flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i],ans[i]=0;
		if(a[i]!=i) flag1=false;
	}
	if(flag1){
		int k;
		for(int i=1;m>=0;i++){
			m-=i;
			k=i;
		}
		cout<<k;
		return 0;
	}
	int k=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=k)
			flag2=false;
	if(flag2){
		int t;
		for(int i=1;m>=0;i++){
			m-=i*k;
			t=i;
		}
		cout<<t;
		return 0;
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j>0;j--){
			cnt+=a[i]-a[j];
			if(cnt>m) break;
			ans[i]++;
		}
	}
	int an=-1;
	for(int i=1;i<=n;i++)
		an=max(an,ans[i]);
	cout<<an;
	return 0;
}