#include<bits/stdc++.h>
using namespace std;

int n,m,k;
const int N = 200005;
int num[N];
int ans = 0;
void dfs(int inx,int val){
	if(k >= m){
		ans = max(ans,val);
		return;
	}
	if(inx >= n){
		return;
	}
	k++;
	for(int i = inx;i < n;i++){
		dfs(i+1,val&num[i]);
	}
	k--;
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>num[i];
	}
	k = 0;
	dfs(0,INT_MAX);
	cout<<ans;
	return 0;
}
