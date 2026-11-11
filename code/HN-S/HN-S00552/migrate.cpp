#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+5;

int c,T;
int x[N];
int dif[N][N];
int sum[N][N];
int remain;
bool flag1=false;
bool f1=false,f2=false;
bool flag2=false;

void solve(){ 
	int n,d;
	cin>>n>>d;
	remain=n;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	if (n==1 || n==2 || n==3){
		cout<<0<<"\n";
		return ;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n-1;j++){
			dif[i][j]=x[j+1]-x[j];//²î·Ö 
			if (dif[i][j]>=d && i==j){
				flag2=true;
				remain=i;
				break;
			}
		} 
		if (flag2==true){
			break;
		}
	}
	if (remain!=n){
		for (int i=1;i<=remain-1;i++){
			for (int j=i;j<=remain-1;j++){
				if (j>=2 && dif[i][j]!=dif[i][j-1] && j>=i+1){
					f1=true;
				}
			}
		}
		for (int i=remain;i<=n-1;i++){
			for (int j=i;j<=n-1;j++){
				if (j>=2 && dif[i][j]!=dif[i][j-1] && j>=i+1){
					f2=true;
				}
			}
		}
		if (f1==false && f2==true){
			if (d-dif[1][1]==1){
				cout<<remain-3<<"\n";	
			}
			else{
				cout<<0<<"\n";
			}
			return ;
		}
		if (f1==true && f2==false){
			if (d-dif[1][1]==1){
				cout<<max(n-remain-2,(int)0)<<"\n";	
			}
			else{
				cout<<0<<"\n";
			}
			return ;
		} 
		if (f1==true || f2==true){
			cout<<0<<"\n";
			return ;
		}
	}
	else{
		for (int i=1;i<=n-1;i++){
			for (int j=i;j<=n-1;j++){
				if (j>=2 && dif[i][j]!=dif[i][j-1] && j>=i+1){
					flag1=true;
				}
			}
		}
		if (flag1==false){
			if (d-dif[1][1]==1){
				cout<<remain-3<<"\n";	
			}
			else{
				cout<<0<<"\n";
			}
			return ;
		}
	}
	for (int i=1;i<=remain;i++){
		for (int j=i+1;j<=remain;j++){
			sum[i][j-1]+=sum[i][j-2]+dif[i][j-1];//Ç°×ººÍ 
		}
	}
	cout<<0<<"\n";
	return ;
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--){
		solve();
	}
	return 0;
}
