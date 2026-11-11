#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
struct dt{
	int a,t;
}brr[N][N]; 
bool cmp(dt x,dt y){
	return x.a>y.a;
}
int arr[N],f[N],k,sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		f[i]=k;
		for(int j=1;j<=k;j++){
			cin>>brr[i][j].a>>brr[i][j].t;
		}
		sort(brr[i]+1,brr[i]+1+k,cmp);
	}
	while(q--){
		cin>>x>>y;
		sum+=arr[x];
		for(int i=1;i<=f[x];i++){
			if(brr[x][i].a==x){
				sum+=brr[x][i].t;
				break;
			}
		}
		for(int i=1;i<=f[x];i++){
			if(brr[x][i].a==y){
				sum+=brr[x][i].t+arr[y];
				cout<<sum<<endl;
				break;
			}
		}
	}
	return 0;
}
