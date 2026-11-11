#include <bits/stdc++.h>
using namespace std;
int z;
int n,m,d,q;
int tk[500005];
int tt[502][400002];
int ttid[502][400002];
int que[100005];
//int num[505];
int num;
long long ans=0;
//void sea(int i,int id,long long nnum,int nex){
//	for(;i<=n;i++){
//		for(int j=1;j<=num[i];j++){
//			if(ttid[i][j]==id){
//				if(nex){
//					nex=0;
//					sea(i+1,ttid[i][])
//				}
//			}
//		}
//	}	
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>z>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>tk[i];
	for(int i=1;i<=n;i++){
//		cin>>num[i];
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>ttid[i][j]>>tt[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>que[i]>>que[++i];
	}
	for(int ww=1;ww<=q;ww+=2){
//		sea(1,que[ww],0,1);
		ans=ans+tk[que[ww+1]]+tk[que[ww]];
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
