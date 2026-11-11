#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500005],ans=1,m1;
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		m1=m;
		int ans1=1;
		for(int j=1;j<i;j++){
			if(m1-(a[i]-a[j])>=0){
				m1-=(a[i]-a[j]);
				ans1++;
			}
			if(i-j==1){
				for(int p=i+1;p<=n;p++){
					if(a[p]==a[i]){
						ans1++;
					}
				}
				if(ans<ans1){
					ans=ans1;
				}
				break;
			}
			else{
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}