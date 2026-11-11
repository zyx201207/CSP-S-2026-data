//宋璇章-西安交通大学附属中学-SN-J00728
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	int a,m1,mon3tr,ans=0;
	cin>>a;
	string mem,m2;
	for(int i=0;i<a;i++){
		cin>>m1>>m2;
		for(int j=0;j<m1;j++){
			mem+=m2;mon3tr++;
		}
	}
	for(int i=0;i<=mon3tr;i++){
		if(mem[i]!=mem[mon3tr-i-1]){
			ans++;
		}
	}
	ans/=2;
	cout<<ans;
	return 0; 
}
