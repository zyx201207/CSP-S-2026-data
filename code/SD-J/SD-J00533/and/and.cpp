#include<bits/stdc++.h>
using namespace std;
int const N=2*1e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m,maxx=0;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n){
		int s=1;
		for(int i=1;i<=n;i++)s=s and a[i];
		cout<<s<<endl;
		return 0;
	}	
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)maxx=max(maxx,int(i and j));
		}
		cout<<maxx<<endl;
		return 0;
	}
	cout<<maxx<<endl;
	return 0;
}

