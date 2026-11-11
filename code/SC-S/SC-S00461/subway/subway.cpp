#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int ktot[M],ttot[N][M];
bool _have[N][M];
int c,n,m,d,q,x,y;
int same_line(int x,int y){
	for(int i=1;i<=n;i++)
	if(_have[i][x]&&_have[i][y]) return i;
	return 0;
}
int find_change_two(){
	int sum=M,_ans=M;
	for(int i=1;i<=m;i++){
        if(_have[1][i]&&_have[2][i]){
        	sum=ttot[1][i]+ttot[2][i];
        	_ans=min(sum,_ans);
		}
	}
	return _ans;
}
int _find(int x){
	for(int i=1;i<=n;i++)
	if(_have[i][x]) return i;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(_have,false,sizeof(_have));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&ktot[i]);
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y;
		    cin>>ttot[i][y];
		    _have[i][y]=true;
		}
	}
	for(int l=1;l<=q;l++){
		cin>>x>>y;
		int ans=0;
		ans+=ktot[x]+ktot[y];
		if(same_line(x,y)){
			ans+=ttot[_find(x)][x]+ttot[_find(y)][y];
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			ans+=ttot[_find(x)][x]+ttot[_find(y)][y];
			ans+=find_change_two();
			cout<<ans<<endl;
		}
	}
	return 0;
}