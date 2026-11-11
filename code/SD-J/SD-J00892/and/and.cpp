#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,mx=0;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	long long ans=a[1];
	if(m==1){
		cout<<mx<<endl;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				cnt=max(cnt,x);
			}
		}
		cout<<cnt<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=1;i<m;i++) ans&=a[n-i];
	cout<<ans<<endl;
	return 0;
}
