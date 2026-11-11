#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,k=1;
long long m,ans=0,cmp[100001011],cnt=1;//ans为 从小到大加的能量
long long a[100010111];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cmp[1]=1;
    for(int i=1;i<=n;i++){
    	if(a[i]==a[i+1]){
    		cmp[k]++;
		}
    	else {
    		k++;
    		cmp[k]=1;
    		ans+=abs(a[i+1]-a[i]);
    		if(ans<=m) {
    		cmp[k]+=k-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cnt=max(cnt,cmp[i]);
	}
	cout<<cnt;
   return 0;
}
