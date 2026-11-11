#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
bool b;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	set<long long> se;
	cin>>n>>m;
	cin>>y;
	cout<<n;
	for(int i=1;i<n;i++){
		cin>>x;
		if(y!=x&&b==0){
			cout<<" "<<(n-i);
			b=1;
		}
	}
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
