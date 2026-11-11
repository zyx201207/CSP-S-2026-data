#include <bits/stdc++.h>
using namespace std;

int love[100000];
bool love1[100000];
int n;
int m1;
int mx=-99999988;

int dfs(int m1,int m){
	int mx1=-99999999;
	if(m>1){
	for(int i=1;i<=n;i++){
		if(love1[i]=0){
		love1[i]=1;
		mx1=max(mx1,m1&dfs(love[i],m-1));
		love1[i]=0;
		}
	}return mx1;
	}
	else{
		return m1;
	}
}

int main(){
	cin >> n >> m1;
	for(int i=1;i<=n;i++){
		cin >> love[i];
	}
	for(int i=1;i<=n;i++){
		if(mx<dfs(love[i],m1)){
			mx=dfs(love[i],m1);
		}
	}
	cout << mx;
	return 0;
}

