#include<bits/stdc++.h>
using namespace std;
int a,b;
string m,n;
int q[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>m>>b>>n;
	if(a==b){
		q[0]=1;
	}
	else{
		for (int i=0;i<4;i++){
			cout<<q[i];
		}
		return 0;
	}
	int c,d;
	c=(m[0]-'0')*10+(m[1]-'0');
	d=(n[0]-'0')*10+(n[1]-'0');
	if(c==d){
		q[1]=1;
	}
	else{
		for (int i=0;i<4;i++){
			cout<<q[i];
		}
		return 0;
	}
	char e,f;
	e=m[2];
	f=n[2]; 
	if((e>='A' and e<='C' and f>='A' and f<='C') or (e>='D' and e<='E' and f>='D' and f<='E')){
		q[2]=1;
	}
	else{
		for (int i=0;i<4;i++){
			cout<<q[i];    
		}
		return 0;
	}
	if(int(e)-int(f)==1 or int(f)-int(e)==1){
		q[3]=1;
	}
	else{
		for (int i=0;i<4;i++){
			cout<<q[i];
		}
		return 0;
	}
	for (int i=0;i<4;i++){
		cout<<q[i];
	}
	return 0;
} 
