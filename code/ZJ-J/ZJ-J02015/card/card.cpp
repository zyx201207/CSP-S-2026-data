#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
struct w_num{
	int w,num;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0;i<n;i++){
		queue<w_num>vis;
		w_num b[300010];
		int I = i+1;
		for(int j = 1+i;j<=n;j++,I++){
			if(b[a[j]].num == 1){
				int x =1;
				bool z= false;
				while(x<=I){
					w_num y= vis.front();
					if(y.w<b[a[j]].w){
						vis.push({y.num,y.w});
						I++;
					}
					b[y.num] = {0,0};
					vis.pop();
					x++;
				}
				I -=x;
			}
			vis.push({j,a[j]});
			b[a[j]] = {j,1};
		}
//		for(int j = 1;j<=m;j++){
//			cout<<b[j].num<<' ';
//		}
//		cout<<endl;
		while(!vis.empty()){
			w_num y = vis.front();
			b[y.num] = {0,0};
			ans[y.num]++;
//			cout<<vis.front()<<' ';
			vis.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}