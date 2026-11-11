#include<bits/stdc++.h>
using namespace std;
const int maxn=510,maxm=5e5+10;
int c,n,m,d,q;
int w[maxm],k[maxn];
struct node{
	int idx;
	int time;
}a[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);	
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].idx>>a[i][j].time;
		}
	}
	for(int i=1;i<=q;i++){
		int sx,sy;
		cin>>sx>>sy;
		long long num=w[sx]+w[sy];
		for(int j=1;j<=n;j++){
			int num1=0,num2=0;
			for(int o=1;o<=k[j];o++){
				if(a[j][o].idx==sx)num1=o;
				if(a[j][o].idx==sy)num2=o;
			}
			if(num1!=0&&num2!=0){
				num+=a[j][num1].time+a[j][num2].time;
			}
		}
		cout<<num<<'\n';
	}
	return 0;
}
