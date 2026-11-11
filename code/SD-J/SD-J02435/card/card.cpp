#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2)
		if(a[i]<a[i-1])
		f=1;
	}
		for(int i=1;i<=n;i++){
			b[i]=i;
			if(a[i]==a[i-1]){
				b[i-1]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=0){
				cout<<b[i]<<" ";
			} 
		}
		
	return 0;
} 
