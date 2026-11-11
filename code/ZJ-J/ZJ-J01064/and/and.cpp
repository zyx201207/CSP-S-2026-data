#include<bits/stdc++.h>
using namespace std;
int n[1000000],m[1000000],yi[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int q,w;
	cin>>q>>w;
	for(int i=1;i<=q;i++){
		cin>>n[i];
		int a=0,x=n[i],y=x,aaa=0;
		while(y>1){
			y=y/2;
			a++;	
		}
		aa=a;
		int gs=0;
		while(x>0){
			if(x>=2^(a-1)){
				x-=2^(a-1);
				gs++;
			}	
			a--;
		}
		if(yi==(aa-1)){
			cout<<n[i];
			return 0;
		}
	}
	
	return 0;
}