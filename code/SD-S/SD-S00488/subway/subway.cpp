#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005];
struct data{
	int now,w;
};
vector<data>h[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		int s;
		scanf("%d",&s);
		for(int j=1;j<=s;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			h[i].push_back({x,y});
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		
	}
	return 0;
}
