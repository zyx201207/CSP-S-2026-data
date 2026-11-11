#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	long long cnt=m,ans=0,maxn=INT_MIN;
	for(int i=2;i<=n;i++){
		long long li=cnt;
		for(int j=i;j>=1;j--){
			m=m-abs(a[i]-a[j]);
			if(m<0){
				m=li;
			}
			else{
				li=m;
				a[j]=a[i];
			}
		}
		for(int j=1;j<=i;j++){
			if(a[j]==a[i]){
				ans++;
			}
		}
		if(ans>maxn){
			maxn=ans;
		}
		m=cnt;
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
		ans=0;
	}
	cout<<maxn;
	return 0;
}
