#include<bits/stdc++.h>
using namespace std;
string b,d;
long long a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long num=0,sum=0,n=0,m=0,q=0,p=0,e=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		q++;
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<b.size()-1;i++){
		num+=b[i];
	}
	for(int i=0;i<d.size()-1;i++){
		sum+=d[i];
	}
	if(num==sum&&q==1){
		p++;
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=b.size()-1;i<b.size();i++){
		n+=b[i];
	}
	for(int i=d.size()-1;i<d.size();i++){
		m+=d[i];
	}
	if(n==65&&m==66&&p==1){
		e++;
		cout<<1;
	}else if(n==66&&m==67&&p==1){
		e++;
		cout<<1;
	}else if(n==65&&m==67&&p==1){
		cout<<1;
	}else if(n==66&&m==65&&p==1){
		e++;
		cout<<1;
	}else if(n==67&&m==66&&p==1){
		e++;
		cout<<1;
	}else if(n==67&&m==65&&p==1){
		cout<<1;
	}else if(n==68&&m==70&&p==1){
		e++;
		cout<<1;
	}else if(n==70&&m==68&&p==1){
		e++;
		cout<<1;
	}else{
		cout<<0;
	}
	if(q==1&&p==1&&e==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
