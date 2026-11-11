#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,x;
	cin>>m>>n;
	int a[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=m;i++){
		if(a[i]%2==1){
			a[i]%=2;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i]=0){
			cout<<0<<' ';
		}else{
			cout<<m-i+1<<' ';
		}
	}
	return 0; 
}
