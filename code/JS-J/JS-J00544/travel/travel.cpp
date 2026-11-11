#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[5]={0,0,0,0,0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[2]=1;
			int z1=s1[2]-'A',z2=s2[2]-'A';
			if((z1<=2&&z2<=2)||(z1>=3&&z2>=3)){
				a[3]=1;
				if(!((z1==2&&z2==0)||(z1==0&&z2==2)))a[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		if(a[i]) cout<<1;
		else cout<<0;
    return 0;
}
