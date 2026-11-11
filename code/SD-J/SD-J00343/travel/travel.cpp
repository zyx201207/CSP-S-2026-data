#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	int xa=0,xb=0,xc=0,xd=0;
	if(ca==cb){
		xa=1;
		int na=(sa[0]-'0')*10+sa[1]-'0';
		int nb=(sb[0]-'0')*10+sb[1]-'0';
		if(na==nb){
			xb=1;
			int ic=0;
			char aa=sa[2],bb=sb[2];
			if(aa>='A'&&aa<='C')ic++;
			else ic--;
			if(bb>='A'&&bb<='C')ic--;
			else ic++;
			if(ic==0){
				xc=1;
				if(aa>='A'&&aa<='C'){
					if(aa-bb==1||aa-bb==-1)xd=1;
				}else xd=1;
			}
		}
	}
	cout<<xa<<xb<<xc<<xd;
	return 0;
}
