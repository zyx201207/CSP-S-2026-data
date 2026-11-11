#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0;
int a[20003],b[20003];
bool aa[20003];
void d(int x){
	if(x>m){
		int c=b[1]&b[2];
		for(int i=3;i<=m;i++){
			c=c&b[i];
		}
		if(c>ma) ma=c;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!aa[i]){
			aa[i]=1;
			b[x]=a[i];
			d(x+1);
			aa[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d(1);
	cout<<ma<<'\n';
	return 0;
}

