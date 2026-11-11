#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct stu{
	int k;
	int t[22];
	int sta[22];
}a[505];
struct st{
	int x,y;
}way[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++){
			cin>>a[i].sta[j]>>a[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>way[i].x>>way[i].y; 
	}
	for(int i=1;i<=q;i++){
		cout<<w[way[i].y]-w[way[i].x]<<endl;
	}
	return 0;
} 
