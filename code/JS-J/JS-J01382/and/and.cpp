#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[200005],maxd=-2e9;
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxd=max(a[i],maxd);
	}
	if(m==1){
		cout<<maxd;
	}
	else if(m==n){
		int tot=a[1];
		for(int i=1;i<=n;i++) tot=tot&a[i];
		cout<<tot;
	}
	else if(m==2){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
	}
	else{
		sort(a+1,a+n+1);
		int num=(n+1)/2;
		cout<<a[num];
	}
}
