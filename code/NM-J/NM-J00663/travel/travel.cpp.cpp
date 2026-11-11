#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a[1]=a[2]=a[3]=a[4]=0;
	if(c1==c2){
		a[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[2]=1;
			char x=s1[2],y=s2[2];
			if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
				a[3]=1;
				if(abs(x-y)==1){
					a[4]=1;
				}
			}
			if(x>='D'&&y>='D'){
				a[3]=1;
				a[4]=1;
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4]<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
