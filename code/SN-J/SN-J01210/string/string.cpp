#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n=0;
	cin>>n;
	int a=0,sum=0;
	char b;
	char c[10000005];
	int num=0;
	for(int i=0;i<=n;i++){
		cin>>a;
		cin>>b;
		sum+=a;
		for(int j=1;j<=a;j++){
			c[sum+j]=b;
		}
	}
	
	for(int i=1;i<=sum/2;i++)
	{
		if(c[i]!=c[sum-i]){
			num+=1; 
		}
	}
	
	cout<<num;
	
	return 0;
}
