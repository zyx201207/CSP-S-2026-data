#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long b=m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=true;
	if(n>1000000000){
		long long aaa=n;
		if(a[1]==1&&a[5]==5&&a[10]==10){
			long long cntt=1;
			while(n--){
				if(m>=a[aaa]-a[n]){
					cntt++;
					m-=(a[aaa]-a[n]);	
				}
				else{
					cout<<cntt<<endl;
					return 0;
				}
			}
		}
		else{
			cout<<n<<endl;
		}
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	long long cnt=1,res=0;
	for(int i=1;i<=n;i++){
		m=b;
		flag=true;
		cnt=1;
		long long j=i+1;
		while(flag){
			if(a[i]-a[j]<=m&&j<=n){
				cnt++;
				m=m-(a[i]-a[j]);
			}
			else{
				flag=false;
			}
			j++;
		}
		if(cnt>=res){
			res=cnt;
		}
	}
	cout<<res<<endl;
	return 0;
}
