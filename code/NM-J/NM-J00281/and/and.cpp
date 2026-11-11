#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100005]={},d=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int v=1;v<b;v++){
		for(int i=1;i<=a;i++){
			for(int f=a;f>i;f--){
			if((c[i]&c[f])>d){
				
			d=c[i]&c[f];
			}
	}
	c[i]=d;
	d=0;
	}
	}
	for(int i=1;i<=a;i++){
		if(c[i]>d){
			d=c[i];
			}
		}
	cout<<d;
	return 0;
}
