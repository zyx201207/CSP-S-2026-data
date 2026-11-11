#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	vector<long long>x;
	vector<char>y;
	for(int i=0;i<n;i++){
		int xn=0;
		char yn='\0';
		cin>>xn>>yn;
		x.push_back(xn);
		y.push_back(yn);
	}
	bool f=true;
	int k=0;
	for(int i=0;i<n;i++){
		char m=y[0];
		if(m==y[i]){
			k+=x[i];
		}else{
			f=false;
			break;
		}
	}
	if(f==true){
		cout<<0;
	}else{
		cout<<k;
	}
	return 0;
}
