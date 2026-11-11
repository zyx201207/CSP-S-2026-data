#include<bits/stdc++.h>
using namespace std;
long long l,n,m,d,x,y,xx,yy,a[510],ss;
struct ck{
	int point[30],len[30],w;
}sb[510];
struct kc{
	int b,c;
}bs[500010];
int bjx(int lai,int xian,int zong){
	for(int i=1;i<=sb[xian].w;i++){
		if(sb[xian].point[i]==lai){
			zong+=sb[xian].len[i];
			break;
		}
	}
	if(xian==yy){
		return zong;
	}
	if(zong>ss){
		return INT_MAX;
	}
	int s=INT_MAX;
	for(int i=1;i<=sb[xian].w;i++){
		if(sb[xian].point[i]!=lai){
		int xy=bjx(xian,sb[xian].point[i],sb[xian].len[i]+zong);
			if(xy<s){
				s=xy;
			}
		}
	}
	return s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>l>>n>>m>>d>>x;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>y;
		for(int j=1;j<=y;j++){
			cin>>bs[j].b>>bs[j].c;
			ss+=bs[j].c;
		}
		for(int j=1;j<=y;j++){
			for(int k=1;k<=y;k++){
				if(j!=k){
					sb[bs[j].b].w++;
					sb[bs[j].b].point[sb[bs[j].b].w]=bs[k].b;
					sb[bs[j].b].len[sb[bs[j].b].w]=bs[k].c;
				}
			}
		}
	}
	for(int i=1;i<=x;i++){
		cin>>xx>>yy;
		cout<<a[xx]+bjx(0,xx,0)+a[yy]<<endl;
	}
    return 0;
}