#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3;
int b1,b2,b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char ch=getchar();
	a1=ch-'0';ch=getchar();
	a1=a1*10+ch-'0';ch=getchar();
	ch=getchar();
	a2=ch-'0';ch=getchar();
	a2=a2*10+ch-'0';ch=getchar();
	if(ch=='F') a3=5;
	else a3=ch-'A'+1;ch=getchar();
	ch=getchar();
	b1=ch-'0';ch=getchar();
	b1=b1*10+ch-'0';ch=getchar();
	ch=getchar();
	b2=ch-'0';ch=getchar();
	b2=b2*10+ch-'0';ch=getchar();
	if(ch=='F') b3=5;
	else b3=ch-'A'+1;ch=getchar();
	if(a1==b1){
		cout<<1;
		if(a2==b2){
			cout<<1;
			if((a3<4&&b3<4)||(a3>3&&b3>3)){
				cout<<1;
				if(abs(a3-b3)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
