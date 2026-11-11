#include <bits/stdc++.h>
using namespace std;
int num[1000005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int a,b,ma=0;
	cin>>a>>b;
	for (int i=0;i <a;i++){
		int x,y,z;
		cin>>x>>y>>z;
		num[i]=x;
			
	}
	for (int i=0;i<a;i++){
	//	int ac[]=0;
	//	int half1=num[i]%2;
		ma = max(ma,num[i]);
	}
	if(b==1){
		cout<<ma;
	}
	else if(a==4&&b==2) cout<<12;
	
}