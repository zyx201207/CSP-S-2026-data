#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
long long n,m;
int num=0,zhong=0;
cin>>n>>m;
zhong=n/2;
for(int i=1;i<=n;i++){
	int x;
	cin>>x;
	if(n==1){
		break;
	}else
	for(int j=1;j<=m;j++){
		if(i==zhong){
			num++;
		}else if(i<zhong){
			x++;
		}
	}
}
cout<<num;
	return 0;
}
