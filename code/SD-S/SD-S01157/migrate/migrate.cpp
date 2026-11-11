#include<bits/stdc++.h>
using namespace std;
long long t,lo,a[1001000],uo,n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>lo>>t;
	cout<<t;
	while(t --){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i ++){
			cin>>a[i];
			if(i == 2){
				uo = a[i] - a[i - 1];
			}
		}
		if(m / uo <= 1){
			cout<<0<<endl;
		}else{
			cout<<uo / m<<endl;
		}
	}
	return 0;
}
//¼Ólonglong
//É¾×¢ÊÍ
//É¾ÎÄ¼þ
