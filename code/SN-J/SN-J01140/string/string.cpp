#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],ans=0,k=0,cnt=0;
	char c[200005],s[200005],b[200005],b1[200005];
	cin>>n;
	//3
	//2 a
	//2 b
	//1 c
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];//总长度 
	}
	for(int i=0;i<n;i++){//补全回文数  
		for(int j=0;j<a[i];j++)s[k+j]=c[i];
		k+=a[i];
	}
	int sum=ans/2;
	for(int i=0;i<sum;i++)b[i]=s[i];
	for(int i=ans;i>sum+1;i--){
		b1[ans-i]=s[i];
	}
	for(int i=0;i<sum;i++){
		if(b[i]!=b1[i])cnt++;
	}
	for(int i=0;i<sum;i++)cout<<i;
	cout<<cnt;
	return 0;
} 
