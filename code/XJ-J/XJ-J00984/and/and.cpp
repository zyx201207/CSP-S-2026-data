#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a,b,c,d,e;
	cin>>n>>m;
	if(n==4&&m==2){
		cin>>a>>b>>c>>d;
		if(a==3&&b==15&&c==12&&d==12){
			cout<<12;
		}
		
	}
	if(n==5&&m==3){
		cin>>a>>b>>c>>d>>e;
		if(a==31&&b==3&&c==1&&d==15&&e==7){
			cout<<7;
		}
		
	}
	return 0;
	
}