#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int len=n/2+1;
	int x=m;
	for(int i=1;i<=n;i++){
		if(x==0)break;
		int y=a[len];
		x-=y-a[i];
		a[i]=a[len];
	}
			
	for(int i=1;i<=n;i++){
		if(a[i]==a[len]){
			cnt++;
		}	
	}
	cout<<cnt;
	return 0;
}
