#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int mid=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		mid=a[3];
	}
	int ans=0,num=0;
	for(int j=2;j<=m;j++){
		for(int i=1;i<=j;i++){
			if(mid>=a[i]) ans+=(mid-a[i]);
			if(mid<a[i]) ans+=(a[i]-mid);
		}
		for(int i=j+2;i<=m;i++){
			if(a[i]==mid) num+=1;
		}
		if(ans<=n){
			num+=3;
			break;
		}
		else mid=a[3+j-1];
	}
	cout<<num;
	return 0;
}