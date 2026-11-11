#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,q=0,s=0;
	cin>>n;
	int b[n]={},w=0;
	char c[n]={};
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i]; 
		w+=b[i];
	} 
	long long a[w]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i];j++){
			a[q]=c[i];
			q++;
		} 
	} 
	for(int i=0;i<q/2+1;i++){
		if(a[i]!=a[q-i-1]){
			s++;
		} 
	}
	
	cout<<s;
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	return 0;
} 
