#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[3000];
	char b[3000];
	char h1[3000],h2[3000]; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	int f=1;
	for(int i=1;i<=n-1;i++){
		if(b[i]!=b[i+1]){
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+a[i];
	}
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=x;j<=a[i]+x-1;j++){
			h1[j]=b[i];
		}
		x=a[i]+x;
	}
	int y=1;
	for(int i=sum;i>=1;i--){
		h2[y]=h1[i];
		y++;
	}
	int c=0;
	for(int i=1;i<=sum;i++){
		if(h1[i]!=h2[i]){
			c++;
		}
	}
	if(c%2==0){
		cout<<c/2;
		return 0;
	}
	if(c%2==1){
		cout<<(c-1)/2;
		return 0;
	}
}
