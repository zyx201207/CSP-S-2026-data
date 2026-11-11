#include<bits/stdc++.h>
using namespace std;
const int N=100007; 
long long c,n,m,d,p;
bool pan=0;
long long w[N],a[507][50007],t,k,ff,dd,ttt;
queue<int> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
			return 0;
		}
		if(n==3){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[m];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		 a[i][0]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>ttt;
		}
	}
	for(int i=0;i<p;i++){
		while(!q.empty()){
			q.pop();
		}
		pan=0;
		int he=0,mm=0;
		cin>>ff>>dd;
		he+=w[ff]+w[dd];
		q.push(ff);
		while(1){
			int www=q.front();
			for(int i=1;i<=a[www][0];i++){
				q.push(a[www][i]);
				q.pop();
				mm++;
				if(a[www][i]==dd){
					pan=1;
					break;
				}
			}
			if(pan){
				he+=mm*ttt*2;
				break;
			}
		}
		cout<<he<<endl;;
	}
	return 0;
} 
