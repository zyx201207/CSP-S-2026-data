#include <bits/stdc++.h>
using namespace std;
/*
B:
即1,2,3,4,5,6,7,8,9,10...2^k
 2^32

*/
int n,m,ans=INT_MIN,a[200005];
bool ax[200005];
void dfs (int id ,int cnt){
	if (id > n+1){
		return;
	}
	if (cnt == m && id <= n+1){
		int sum=0;
		bool flag = 0;
		for (int i=1;i<=n;i++){
			if (ax[i] && !flag){
				sum=a[i];
				flag=1;
			}
			else if (ax[i]){
				sum &=a[i];
			}
		}
		ans=max (ans,sum);
		return ;
		
	}
	//选这个数
	//num有初值 
	ax[id]=1;
	dfs (id+1,cnt+1) ;
	
	
	//不选这个数
	ax[id]=0;
	dfs (id+1,cnt); 
	
}

int main (){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	dfs (1,0);

	cout <<ans;
	return 0;
}

