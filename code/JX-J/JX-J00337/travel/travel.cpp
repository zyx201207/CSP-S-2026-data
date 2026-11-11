#include<bits/stdc++.h>
using namespace std;
char a[10],a1[10];
char b[10],b1[10];
bool chexiang=true;
bool pai=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",a);
	scanf("%s",a1);
	scanf("%s",b);
	scanf("%s",b1);
	int a1len=strlen(a1),b1len=strlen(b1);
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]) chexiang=false;
		if(a1[i]!=b1[i]) pai=false; 
	}
	if(chexiang==false) cout<<0;
	else cout<<1;
	if(pai==false || chexiang==false) cout<<0;
	else cout<<1;
	char x=a1[a1len-1],y=b1[b1len-1];
	if(pai==false || chexiang==false) cout<<0;
	else{
	    if(x=='A' || x=='B' || x=='C'){
		    if(y!=x && (y=='A' || y=='B' || y=='C')){
			    cout<<1;
		    }
		    else cout<<0;
	    }else{
		    if(y!=x &&(y=='D'|| y=='E')){
			    cout<<1;
		    }else cout<<0;
	    }
    }
    if(pai==false || chexiang==0) cout<<0;
    else{
	    if(x=='A' && y=='B') cout<<1;
	    else if(x=='B' && (y=='C' || y=='A')) cout<<1;
	    else if(x=='C' && y=='B') cout<<1;
	    else if(x=='D' && y=='E') cout<<1;
	    else cout<<0;
    }
	return 0;
}
