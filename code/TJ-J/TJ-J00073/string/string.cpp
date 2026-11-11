#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a;
	int num=1;
	int cnt=0;
	cin>>n;
	char c[10000000]={};
	char c1;
	for(int i=1;i<=3;i++){
		cin>>a;
		cin>>c1;
		for(int j=1;j<=a;j++){
			c[num]=c1;
			cout<<c[num]<<endl;
			num++;
		}
	}
	for(int i=1;i<=n/2+1;i++){
		if(c[i]!=c[num-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
