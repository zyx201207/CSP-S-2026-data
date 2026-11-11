#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m
	cin>>n>>m;
	vector<int>vec;
	for(int i=0;i<n;i++){
		int f;
		cin>>f;
		vec.push_back(f);
	}
	int l=vec[0];
	if(m==n){
		for(int i=0;i<n;i++){
			l&=vec[i];
		}
	}else if(m==1){
		for(int i=0;i<n;i++){
			if(vec[i]>l){
				l=vec[i];
			}
		}
	}
	cout<<l;
	return 0;
} 
