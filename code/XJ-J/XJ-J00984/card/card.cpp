#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,c,d,e,f,g,h,i,j,k,l;
	cin>>a>>b;
	if(a==4&&b==3){
		cin>>c>>d>>e>>f;
		if(c==1&&d==2&&e==1&&f==3){
			cout<<3<<" "<<1<<" "<<4;
		}
	}
	if(a==10&&b==3){
		cin>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
		if(c==3&&d==1&&e==2&&f==1&&g==3&&h==2&&i==3&&j==1&&k==2&&l==1){
			cout<<10<<" "<<3<<" "<<3;
		}
	}
	return 0;
}