#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,sum;
int f(int o){
	if(o<1)return 0;
	else if(o<3)return 2;
	return f(o-1)+o/2;
}int main(){
	freopen(".in","r",stdin),freopen(".in","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		sum=0;
		cout<<f(n)<<' ';
	}return 0;
}
