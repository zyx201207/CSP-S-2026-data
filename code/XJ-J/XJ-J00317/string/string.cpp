#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ze=0;
	vector<char>vec;
		cin>>n;
		char b;	int x;
	for(int i=0;i<n;i++){
	
		
		cin>>x>>b;
		
		for(int j=0;j<x;j++){
			vec.push_back(b);
			
		}
	}
	ze=vec.size();
	int num=0,ans=0;
	
	
	for(int i=0,j=ze/2+(ze%2);j<ze;j++,i++){
		
		if(vec[i]!=vec[j]){
			
			num+=1;
		}
	}
	
	
	cout<<num;
	return 0;
}