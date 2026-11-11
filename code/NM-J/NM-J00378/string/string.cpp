#include<bits/stdc++.h>
using namespace std;
char c;
long long ans=0,n,cnt=0,x,r=0,l=0;
struct paiir{
	long long f;
	char s;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<paiir> sum(n);
	for(long long i=0;i<n;i++){
		cin>>x;
		cin>>sum[i].s;
		cnt+=x;
		sum[i].f=cnt;
	}
	r=n-1;
	for(long long i=0;i<cnt/2;i++){
		if(sum[l].f<i+1){
			l++;
		}
		if(sum[r-1].f>=cnt-i){
			r--;
		}
		if(sum[l].s!=sum[r].s){
			ans++;
		}
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
