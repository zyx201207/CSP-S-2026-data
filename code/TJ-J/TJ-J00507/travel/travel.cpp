#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[5],s2[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	int p1=(s1[1]-'0')*10+(s1[2]-'0');
	int p2=(s2[1]-'0')*10+(s2[2]-'0');
	//cout<<p1<<' '<<p2;
	//cout<<c1<<' '<<c2;
	int f=0;
	if(c1==c2) cout<<1;
	else{
		f=1;
		cout<<0;
	}
	if(f==0&&p1==p2) cout<<1;
	else{
		f=1;
		cout<<0;
	}
	if(f==0&&((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D'))){
		cout<<1;
	}
	else{
		f=1;
		cout<<0;
	}
	int a=s1[3],b=s2[3];
	if(a>b){
		int h=a;
		a=b;
		b=h;
	}
	if(f==0&&((b-1==a&&b!='D')||(b-2==a&&b=='F'))){
		cout<<1;
	}
	else{
		f=1;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
