#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,k[500010],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		k[i]=a[i]-a[i-1];
	}
	int mans=1;
	for(int i=1;i<n;i++){
		int ans=1;
		long long cnt=0,cnt_=0;
		for(int j=i-1;j>0;j--){
			cnt_+=k[j],cnt+=cnt_;
			if(cnt<=m){
				ans++;
			}
			else{
				break;
			}
		}
		mans=max(mans,ans);
	}
	cout<<mans;
	return 0;
}

