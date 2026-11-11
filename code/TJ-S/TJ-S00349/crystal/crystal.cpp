#include <bits/stdc++.h>
using namespace std;

long long n,m,num,maxans=-1,ans=1,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	num==m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
    	for(int j=i;j>=1;j--){
    		if(num<a[i]-a[j]){
    			break;
			}
			ans++;
			num-=a[i]-a[j];
		}
		maxans=max(maxans,ans);
		ans=1; num=m;
	}
	cout<<maxans;
	return 0;
}
