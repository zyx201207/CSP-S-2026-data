#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],c[1000000],d[1000000];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n=0,m=0,k=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			b[a[i]]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(b[a[i]]!=2){
			cout<<n-i;
		}
		b[a[i]]++;
	}
	return 0;
}

