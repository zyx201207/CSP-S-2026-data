#include<bits/stdc++.h>
using namespace std;
int z;
bool an1[1073741824];
int yu(int i,int j){
	int k=0,f=1;
	while(i||j){
	    k+=((i%2)&&(j%2))*f;
	    f*=2;
	    i/=2;
	    j/=2;
	}
	return k;
}
int y(vector<int> a){
	int k;
	k=yu(a[0],a[1]);
	for(int i=2;i<a.size();i++){
		k=yu(k,a[i]);
	}
	return k;
}
void dfs(vector<int> a,vector<int>b,int j,int m){
	if(j==m){
		if(y(b)>z)z=y(b);
		return ;
	}
	for(int i=0;i<a.size();i++){
		if(!an1[i]){
			an1[i]=1;
			b.push_back(a[i]);
			dfs(a,b,i+1,m);
			b.pop_back();
			an1[i]=0;
	    }
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),ans;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs(a,ans,0,m);
	cout<<z;
	return 0;
}
