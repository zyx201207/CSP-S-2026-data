#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=-14514;
int main(){
    freopen("and3.in","r",stdin);
    freopen("and3.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n-m+1;i++){
		cnt=a[i];
		for(long long j=0;j<m-1;j++){
			cnt=cnt&a[j+i];
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
//阿弥陀佛，神兽保佑 内蒙一等
//         _------------_
//         |			|
//         |	>	<	|
//         |			|
//         |	____	|
//         	 |	|	| |
//           |	|	| |
//           |__|	|__|
//	
