#include<bits/stdc++.h>
using namespace std;
int a[500005],maxn=-1,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=1||a[1]!=1)flag=1;
	}
	if(!flag){
		b[2]=1;
		for(int i=3;;i++){
			b[i]=b[i-1]+i-1;
			if(b[i]>m){
				cout<<i-1;
				return 0;
			}
			if(b[i]==m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long mm=m;
		int cnt=1;
		for(int j=i-1;j>=1;j--){
			long long sum=a[i]-a[j];
			//cout<<a[i]<<" "<<a[j]<<endl;
			mm-=sum;
			if(mm>=0)cnt++;
			else break;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
 