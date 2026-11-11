#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,y;
int k1,k2,k3,k4;
char a[5],b[5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a+1>>y>>b+1;
	int ha=(a[1]-'0')*10+(a[2]-'0'),hb=(b[1]-'0')*10+(b[2]-'0');
	if(x==y){
		k1=1;
		if(ha==hb){
			k2=1;
			if(a[3]>='A'&&a[3]<='C'&&b[3]>='A'&&b[3]<='C'||a[3]>='D'&&a[3]<='F'&&b[3]>='D'&&b[3]<='F'){
				k3=1;
				if(a[3]+1==b[3]||a[3]-1==b[3]||(a[3]=='D'&&b[3]=='F')||(a[3]=='F'&&b[3]=='D')){
					k4=1;
				}
			}
		}
	}
	cout<<k1<<k2<<k3<<k4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
