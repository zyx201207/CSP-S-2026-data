#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai;
	char ci;
	cin>>n;
	int x;
	char a[x];
	int s=0;
	for(int j=1;j<=n;j++){
		cin>>ai>>ci;
		x=n*ai;
	}
	for(int i=0;i<=x;i++){
		a[i]+=ai*'ci';
		s=i/2;
	}
	if(x%2!=0)
	cout<<s;
	else
	cout<<s-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
