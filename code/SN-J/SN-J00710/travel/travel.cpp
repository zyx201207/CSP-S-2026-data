//杨云铄 西安市第二十六中 SN-00710 
#include<iostream>
#include<string>
using namespace std;
bool w1=0,w2=0,w3=0; 
char wen1(char p[2],char l[2])
{
	if(p[0]==l[0] && p[1]==l[1])cout<<1;
	else{
		cout<<0;
		w1=1;
	}
}
char wen2(char q[3],char z[3])
{
	if(q[0]==z[0] && q[1]==z[1] && w1==0)cout<<1;
	else{
		cout<<0;
		w2=1;
	}
}
char wen3(char e[3],char c[3])
{
	if(e[2]=='A' && c[2]=='B' && w2==0) cout<<1;
	else if(e[2]=='A' && c[2]=='C' && w2==0) cout<<1;
	else if(e[2]=='B' && c[2]=='C' && w2==0) cout<<1;
	else if(e[2]=='C' && c[2]=='A' && w2==0) cout<<1;
	else if(e[2]=='C' && c[2]=='B' && w2==0) cout<<1;
	else if(e[2]=='B' && c[2]=='A' && w2==0) cout<<1;
	else if(e[2]=='D' && c[2]=='F' && w2==0) cout<<1;
	else if(e[2]=='F' && c[2]=='D' && w2==0) cout<<1;
	else{
		cout<<0;
		w3=1;
	}
}
char wne4(char w[3],char d[3])
{
	if(w[2]=='A' && d[2]=='B' && w3==0) cout<<1;
	else if(w[2]=='B' && d[2]=='C' && w3==0) cout<<1;
	else if(w[2]=='D' && d[2]=='F' && w3==0) cout<<1;
	else if(w[2]=='B' && d[2]=='A' && w3==0) cout<<1;
	else if(w[2]=='C' && d[2]=='B' && w3==0) cout<<1;
	else if(w[2]=='F' && d[2]=='D' && w3==0) cout<<1;
	else{
		cout<<0;
	}
}
int main()
{
	char a[3],b[3],n[2],m[2];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);    
    for(int i=0;i<2;i++) cin>>n[i];
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<2;i++) cin>>m[i];
    for(int i=0;i<3;i++) cin>>b[i];
    wen1(n,m);
    wen2(a,b);
    wen3(a,b);
    wne4(a,b);
    return 0;
}
