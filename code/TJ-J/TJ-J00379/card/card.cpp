#include <bits/stdc++.h>
using namespace std;
int num[300005];
int f(int a[],int b,int n){
	for(int i=1;i<=n;i++){
		if(a[i]==b) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int desk[n+1],l=1,r=1;
		for(int j=i;j<=n;j++){
			desk[r]=a[j];
			if(f(desk,a[j],r)) r=f(desk,a[j],r);
			r++;
		}
		for(int j=1;j<r;j++){
			num[desk[j]]++;
			desk[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
