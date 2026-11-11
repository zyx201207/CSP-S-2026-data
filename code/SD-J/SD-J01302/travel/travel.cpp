#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,aa,b,bb;
	cin>>a>>aa>>b>>bb;
	int x=stoi(a),y=stoi(b);
	int i=0,j=0,k=0,z=0;
	if(x==y){
		cout<<1;
		i=1;
}
	else{
		cout<<0;
	}
	string q;
	q[0]=aa[0];
	q[1]=aa[1];
	q[2]=aa[2];
//	cout<<q[0]<<q[1];
	string w;
	w[0]=bb[0];
	w[1]=bb[1];
	w[2]=bb[2];
	//cout<<w[0]<<w[1];
	if(w[0]==q[0]&&q[1]==w[1]&&i==1){
		cout<<1;
		j=1;
}
	else{
		cout<<0;
	}
	if(j){
	
	if((w[2]=='A'||w[2]=='B'||w[2]=='C')&&(q[2]=='A'||q[2]=='B'||q[2]=='C')||(w[2]=='D'||w[2]=='F')&&(q[2]=='D'||q[2]=='E')){
		cout<<1;
		k=1;
	}
	else{
		cout<<0;
	}
}
	if(!j) cout<<0;
	
//	cout<<k;
	if(j&&k){
	

			if(q[2]+1==w[2]||q[2]-1==w[2]) {
				cout<<1;
				z=1;
		}
		
	//	cout<<"     "<<z<<k;
		if(z==0){
			cout<<0;
		}
	}
	else if(z==0){
	
		cout<<0;
	}
	
	//	cout<<888;
	
	
	
	return 0;
} 
