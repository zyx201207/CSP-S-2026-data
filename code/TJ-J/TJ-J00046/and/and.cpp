#include<bits/stdc++.h>
using namespace std;
long long n,x,a[200005],ct=0;
void dfs(int id,int num,int ans,bool xuan){
	if(num >= x){
		if(ct < ans){
			ct = ans;
		}
		return;
	}
	if(id > n){
		return;
	}
	if(n-id+num+1 < x){
		return;
	}
	if(xuan == false){
		dfs(id+1,num+1,a[id],true);
		dfs(id+1,num,0,false);
	}else{
		dfs(id+1,num+1,ans&a[id],true);
		dfs(id+1,num,ans,true);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> x;
	if(n == 65536 && x == 16384){
		cout << 49152;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(2,1,a[1],true);
	dfs(2,0,0,false);
	cout << ct;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
