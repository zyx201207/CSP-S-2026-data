#include<bits/stdc++.h>
using namespace std;	
string as,sa;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;

	for(int i=1;i<=a;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			as+=y;
		}
	}
	//cout<<as;
	int b=as.size();
	for(int i=b-1;i>=0;i--){
		sa+=as[i];
	}
//	cout<<sa<<endl;
	int num=0;
	for(int i=0;i<=b;i++){
		if(as[i]!=sa[i]){
			cout<<i<<" ";
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
