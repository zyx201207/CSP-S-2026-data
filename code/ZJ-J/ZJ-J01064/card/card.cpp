#include<bits/stdc++.h>
using namespace std;
int a[1000000],p[1000000],z[1000000];
void abc(int x,int y){
	int s=0;
	for(int i=x;i<=y;i++){
		p[i]=a[i];
		s++;
		for(int j=1;j<=s;j++){
			if(p[i]==p[j]){
				abc(x+s,y);
				continue;
			}
		}
		if(x+s-1==y){
			for(int i=x;i<=y;i++) z[p[i]]++;
		}
	}
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		abc(i,n);
	}
	for(int i=1;i<=m;i++) cout<<z[i]<<" ";
	return 0;
}