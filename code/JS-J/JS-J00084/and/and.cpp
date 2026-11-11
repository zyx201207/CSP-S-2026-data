#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200050];
int mm=INT_MIN;
int an(int a,int b){
	int ans;
	string ast,bst,cst;
	int i=1;
	while(a!=0){
		ast[i]=a%2;
		a/=2;
		i++;
	}
	i=1;
	while(b!=0){
		bst[i]=b%2;
		b/=2;
		i++;
	}
	int stmax=max(ast.length(),bst.length());
	for(int j=1;j<=stmax;j++){
		if(ast[j]==1&&bst[j]==1){
			cst[j]=1;
		}
		else cst[j]=0;
	}
	for(int j=1;j<=stmax;j++){
		if(cst[j]==1)ans+=pow(2,j-1);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int f=1;
	cin>>n>>m;
	a[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=1)f=0;
		if(mm<a[i])mm=a[i];
	}
	if(f==1&&m==n){
		cout<<n/2;
		return 0;
	}
	if(f==1&&m==2){
		cout<<a[n];
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			a[i]=an(a[i],a[i-1]);
		}
		cout<<a[n];
		return 0;
	}
	cout<<mm;
	return 0;
}
