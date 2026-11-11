#include<bits/stdc++.h> 
#define ll long long
using namespace std;

const int N = 2e5+5;

int a[N];
int ans = 0;
int n,m;

// pos:当前选到第pos个  cnt:选了cnt个。，num按位与 
void dfs(int pos,int cnt,int num){
	if(cnt==m){
		ans = max(ans,num);
		return ; 
	}
	if(pos==n+1){
		return ;
	}
	
	// 选当前数
	if(cnt==0){		// 当前没有选数 
		dfs(pos+1,cnt+1,a[pos]);
		//cout<<a[pos]<<" ";
	} else{
		dfs(pos+1,cnt+1,num&a[pos]);
	}
	
	
	dfs(pos+1,cnt,num);
}

bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	

	cin>>n>>m;
	
	int maxx = 0,sum = 0,minn = 1e9;
	bool isPow = true;
	bool isB = true;
	if(n&(n-1)!=0)	isB = false;		// n不是2的幂 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
		if(i==1){
			sum = a[1];
		} else{
			sum &= a[i]; 
		}
		if(a[i]+1&(a[i])!=0){		// 不满足性质A 
			isPow = false;
		}
		if(a[i]!=i-1){
			isB=false;
		}
	}
	
	// 骗分 ----
	if(n>20){
		int max1 = 0;
		if(m==n){
			cout<<sum;
			return 0;
		} else if(m==1){
			cout<<maxx;
			return 0;
		} else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					max1 = max(max1,a[i]&a[j]);
				}
			}
			cout<<max1;
			return 0;
		} else if(isPow){		// 特殊性质A 
			sort(a+1,a+n+1,cmp);
			
			int min11 = 1e9;
			for(int i=1;i<=m;i++){
				min11 = min(min11,a[i]);
			}
			cout<<min11;
			return 0;
		} else if(isB){
			if(m>n/2){
				cout<<0; 
			} else{
				cout<<n/2;
			}
			return 0;
		}
	}
	
	// -----
	
	
	dfs(1,0,0);
	
	cout<<ans;
	return 0;
}
