#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5,M=3e5+5;
int a[N],b[N],tot=1,c[M];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
//		cout<<"局数:"<<i<<'\n';
		for(int j=i;j<=n;j++){
//			cout<<"打入的纸牌:"<<a[j]<<'\n';
			for(int k=1;k<=tot-1;k++){
				if(b[k]==a[j]){
//					cout<<"是否触发清场:"<<"YES"<<'\n';
					for(int op=k+2;op<=tot-1;op++)
					b[i]=0;
					tot=k;
//					cout<<"清场tot:"<<tot<<'\n';
					break;
				}
			}
			b[tot]=a[j];
			tot++;
//			cout<<"每局每次操作后的变化:"<<'\n'; 
//			for(int k=1;k<=tot-1;k++) cout<<b[k]<<' ';
//			cout<<'\n';
//			cout<<"操作后的 tot:"<<tot<<'\n'; 
		}
//		cout<<"每局结束后的变化:"<<'\n'; 
//		for(int k=1;k<=tot-1;k++) cout<<b[k]<<' ';
//		cout<<'\n';
		for(int fu=1;fu<=m;fu++){
			for(int kfu=1;kfu<=tot-1;kfu++){
//				cout<<"比对"<<b[kfu]<<':'<<fu ;
				if(b[kfu]==fu){
//					cout<<"存入"<<"c["<<fu<<']'<<'\n';
					c[fu]++;
				} 
				else continue;
			}
		}
		memset(b,0,sizeof(b));
		tot=1;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}

