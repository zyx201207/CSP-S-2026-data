#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
int n,m;
int a[maxn];
int ans,num=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==n){
		for(int i=0;i<n;i++){
			ans=a[i]&a[i+1];
			cout<<ans;
			return 0;
		}
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n-1];
	}
	else if(m==2){
		sort(a+1,a+n+1);
		num=a[n-1]&a[n-2];
		cout<<num;
		return 0;
	}
	cout<<num;
	return 0;
}
