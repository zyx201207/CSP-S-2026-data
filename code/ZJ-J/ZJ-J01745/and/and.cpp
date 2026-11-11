#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,maxv,ans_da;
bool vx[200005][35];//vx[i][1]:2^0,vx[i][2]:2^1...vx[i][30]:2^29
bool ans[35];
bool canc[200005];//能不能选,0可以,1不可以
 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int num,j=0;
		cin >> num;
		while(num>0){
			j++;
			vx[i][j]=(num%2);
			num/=2;
		}
		maxv=max(maxv,j);
	}
	for(int i=maxv;i>=1;i--){
		int num=0;
		for(int j=1;j<=n;j++){
			if(canc[j]==0&&vx[j][i])num++;
		}
		if(num>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++){
				if(vx[j][i]==0)canc[j]=1;
			}
		}
	} 
	int vo2=1;
	for(int i=1;i<=maxv;i++){
		if(ans[i]==1)ans_da+=vo2;
		vo2*=2;
	} 
	cout << ans_da;
	return 0; 
}
