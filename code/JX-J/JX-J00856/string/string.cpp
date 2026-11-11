#include<bits/stdc++.h>
using namespace std;
string s;
char m[1000000005];
int a,mi=1e9;
int hw(string q){
	if(q.size()==1)return 1;
	for(int i=0,j=q.size(); i>=j; i++,j--){
		if(q[i]!=q[j])
		return 0;
	}
	return 1;
}
void d(int id,string z){
	if(id+1==a)
	 return;
	if(hw(z)==1){
		if(id<mi)
		mi=id;
	}
	int v=z.size();
	for(int i=0; i<a; i++){
		for(int k=0; k<v; k++){
			char x=z[k];
			z[k]=m[i];
			d(id+1,z);
			z[k]=x;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int z=0;
	cin>>a;
	for(int i=0; i<a; i++){
		int n;
		cin>>n>>m[i];
		for(int j=1; j<=n; j++){
			s[z]=m[i];
			z++;
		}
	}
	d(0,s);
	if(mi==1000000000)
	cout<<z;
	else
	cout<<mi;
	return 0;
}
