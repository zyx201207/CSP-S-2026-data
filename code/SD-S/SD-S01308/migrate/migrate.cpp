#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005],c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
			double l=d*1.0/(a[1]-a[2]);
			int x=int(l);
			if(x!=1&&x!=0) cout<<(n-(x-1)*2-1)<<" ";
			else cout<<0<<' ';
	}
	
	return 0;
}
//zhen de hao yun nan a;
//A B C ben lei nen zuo chu lei de
//nao zi hao hun luan
// lose 20 point 

//75+0(20)+0(28)+0 jin li le 
