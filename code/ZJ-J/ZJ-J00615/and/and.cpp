#include<bits/stdc++.h>
using namespace std;
#define MAX int(2e5+1000)
int n,m;
int a[MAX];
int dfs(int i,int last,int yu){
	if(yu==0)return last;
	if(i+yu-1>n)return 0;
	int A=dfs(i+1,last,yu);
	int Now=last & a[i];
	int B=dfs(i+1,Now,yu-1);
	return max(A,B);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,2147483647,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
