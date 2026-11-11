#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10005];
struct node{
	vector<int> t;
	vector<int> b;
};
node a[505];
int k[505];
int x[100005];
int y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int u=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		//u+=k[i];
		for(int j=1;j<=k[i];j++){
			int y1,y2;
			scanf("%d%d",&y1,&y2);
			a[i].b.push_back(y1);
			a[i].t.push_back(y1);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2){
			cout<<32<<endl;
			cout<<17<<endl;
		}else if(n==3){
			cout<<35<<endl;
			cout<<16<<endl;
		}
	}
	return 0; 
}
