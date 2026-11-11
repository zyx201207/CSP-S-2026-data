#include<bits/stdc++.h>
using namespace std;

int a[20005];
string b[20005];
string c[100000005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.on","w",stdout);
	int d=1;
	int num=0;
	int e=1; 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
		for(int j=d;j<=d+a[i];j++){
			c[j]=b[i];
		}
		d+=a[i];
	}
		int sum=c[100000005].size();
	string a1[sum],b1[sum];
	for(int i=1;i<(sum+1)/2;i++){
		a1[i]=c[i];
	}
	for(int i=sum;i>=(sum+1)/2;i--){
		b1[e]=c[i];
		e++;
	}
	for(int i=1;i<=(sum+1)/2;i++){
		if(a1[i]!=b1[i])num++;
	}
	cout<<num;
	return 0;
}
