#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,M=5010;
long long int  x[N],pre[N];
long long int cod[M][M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long int n,d,cnt=0,flag=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			pre[i]=x[i]-x[1];
			if(i>=3){
				if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
					flag=0;
				}
			}
		}
//		if(d==1){
//			cout<<0<<"\n";
//			continue;
//		}
//		if(flag==1){
////			cout<<n<<" "<<d<<" "<<x[2]-x[1]<<" ";
//			if((x[2]-x[1])*2<=d&&(x[2]-x[1])*3>d){
//				cout<<n-3<<"\n";
//			}else cout<<0<<"\n";
//			continue;
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pre[j]-pre[i]<=d||j==i+1){
					cod[i][j]=1;
				}
			}
		}
		for(int len=3;len<=n;len++){
			for(int i=1;i<=n;i++){
				int j=i+len;
				if(j>n)break;
				for(int k=i+1;k<j;k++){
					cod[i][j]+=cod[i][k]*cod[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(cod[i][j]==2){
					cnt++;
				}
				cod[i][j]=0;
			} 
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
/*
0 1
8 6
1 4 7 10 13 16 19 22 
6-7-8
3-4-5
0 1
4 2
1 2 3 4 
1-2-3-4
*/
