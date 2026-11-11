#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<string> a;
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long x;
		string y;
		cin>>x>>y;
		for(long long i=0;i<x;i++){
			a.push_back(y);
		}
	}
	long long len=a.size()-1;
	long long sum=len;
	long long res=0;
	if(len%2==0){
		while(1){
			if(len<sum/2) break;
			string j=a[len];
			string i=a[0];
			if(i!=j){
				res++;
			} 	
		}
	}else{
		while(1){
			if(len<sum/2+1) break;
			string j=a[len];
			string i=a[0];
			if(i!=j){
				res++;
			} 
			len--;	
		}
		res--;
	}
	cout<<res<<endl;
	return 0;
}
