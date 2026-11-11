#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin); 
	//freopen("string.out","w",stbout);
	int n;
	cin>>n;
	string c;
	int a;
	string sum;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		sum=sum+c;
	}
	for(int i=0;i<n;i++){
		if(sum[6]==sum[2]){
			cout<<sum[2]<<sum[3];
		}
	}
	return 0;
}        