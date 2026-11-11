#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		cin>>sum;
		char b;
		cin>>b;
		for(int j=1;j<=sum;j++){
			a[j+len]=b;
		}
		len+=sum;
	}
	int i=len/2,j=len/2+1;
	int num=0;
	while(i>=1&&j<=len){
		if(a[i--]!=a[j++]){
			num++;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdut);
}