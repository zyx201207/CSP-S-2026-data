#include<bits/stdc++.h>
using namespace std;
int a[1000000],n,m;
int b[1000000];
vector <int>v;
bool check(int ind){
	int i=0;
	while(i<v.size()){
		if(a[i]==v[ind]){
			return true;
		}
	}
	return false;
}
void solve(){
	for(int i=0;i<v.size();i++){
		
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(check(j)){
				v.pop(j,v.end());
				continue;
			}
			v.push_back(a[j]);
		}
	}
	return 0;
}
