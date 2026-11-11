#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
int n,m;
int a[N];
bool is_visited[N];
long long Max=-1;
void dfs(int cnt,int sum){
	if(cnt==m){
		if(sum>Max){
			Max=sum;
		}
		return;
	}
	else{
		for(int i=0;i<n;i++){
			if(is_visited[i]==0){
				is_visited[i]=1;
				dfs(cnt+1,(sum&a[i]));
				is_visited[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		is_visited[i]=1;
		dfs(1,a[i]);
		is_visited[i]=0;
	}
	cout<<Max;
	return 0;
}

