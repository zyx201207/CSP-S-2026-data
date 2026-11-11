#include<bits/stdc++.h>
using namespace std;
struct subway{
	int num;
	int huan; 
}a[501];
int ma[501][501];
int c,n,m,d,p,k;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>ma[0][i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		while(k){
			k--;
			cin>>subway.num>>subway.huan;
		}
	}
	return 0;
}
