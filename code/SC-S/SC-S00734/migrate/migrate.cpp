#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+10;
int n,d;
int a[N],rgt[N];

int num=0,res;
void dfs(int idx,int ed,int need){
	if(idx == ed){
		if(need == 0){
			++ num;
		}
		return ;
	}
	if(need == 0 || idx > ed) return ;
	
	for(int i=idx+1;a[i]-a[idx]<=d;i++){
		dfs(i,ed,need-1);
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	
	int task,Q;
	cin>>task>>Q;
	
	int pos,res;
	while(Q --){
		cin>>n>>d;
		
		
		for(int i=1;i<=n;i++) cin>>a[i];
		
		
		res=0;
		for(int i=1;i<=n;i++){
			
			for(int j=i+1;j<=n;j++){
				bool flag=true;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[k-1]>d) flag=false;
				}
				if(!flag) break;
				
				
				int stp=0,p=i;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[p] > d) stp++,p=k;
				}
				stp++;
				
				
				num=0;
				dfs(i,j,stp);
				//cout<<num<<'\n';
				if(num==2) res++;
			}
		}
		
		cout<<res<<'\n';
	}
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/