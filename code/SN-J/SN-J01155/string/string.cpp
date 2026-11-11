#include<bits/stdc++.h>
using namespace std;
//string a,b;
//int c[1001][1001];
string a;
//gxez zhangshuchang
long long neeed=0;
long long b[1000000];
char c[1000000];
string check;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
		check+=c[i];
	}
	bool index=0;
	for(int i=0;i<n;i++){
		if(check[i]==check[check.size()-i-1]){
			continue;
		}
		else{
			index=1;
			break;
		}
	}
	if(index==0){
		cout<<0;
		return 0; 
	}
	for(int i=0;i<(n/2+n%2);i++){
		
		if(i==check.size()-i-1){
			neeed-=1;
		}
		else if(check[i]==check[check.size()-i-1]){
			continue;
		}
		else{
			neeed+=b[i]+b[check.size()-i-1];
		}
	}
	cout<<neeed;
	return 0;
}
