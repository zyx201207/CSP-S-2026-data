#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int f=0;
	int g[10005];
	for(int i=0;i<=a;i++){
		cin>>g[i];
}
int d=0;
	if(b=2){
		for(int i=0;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				f=g[i]&g[j];
				d=max(d,f);
			}
		}
	}
		if(b=3){
		for(int i=0;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				f=g[i]&g[j];
				for(int y=i+2;y<=a;y++){
					f=f&g[y];
					d=max(d,f);
				}
			}
		}
	}
	cout<<d;
	return 0;
} 

