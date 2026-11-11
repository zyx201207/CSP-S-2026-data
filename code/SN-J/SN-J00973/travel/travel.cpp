#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10],c2[10],x1[10],x2[10];
	cin>>c1>>x1>>c2>>x2;
	if(c1[1]==c2[1]&&c1[0]==c2[0]){
		cout<<"1";
		if(x1[1]==x2[1]&&x1[0]==x2[0]){
			cout<<"1";
			int l1=x1[2]-0;
			int l2=x2[2]-0;
			if(l1>=65&&l1<=67&&l2>=65&&l2<=67){
				if(abs(l1-l2)==1) cout<<"11"<<endl;
				else cout<<"10"<<endl;
			}
			else if(abs(l1-l2)==2&&l1!=66&&l2!=66) cout<<"11"<<endl;
			else cout<<"00"<<endl;
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
}

