#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
int x[999999];
int main(){
cin>>c>>t;
cin>>n>>d;
for(int j=1;j<=t;j++){
	for(int i=1;i<=n;i++){
	cin>>x[i];
	if(d==2){
	for(int ii=2;ii<=n/2;ii+2){
	for(int jj=1;jj<=n;jj++){
		if((2+ii)<=n){
			if(x[jj]+1+ii<=x[n]){
			ans++;
		}
	}
}}

}
	if(d==3){
	for(int iii=2;iii<=n/2;iii+3){
	for(int jjj=1;jjj<=n;jjj++){
		if((2+iii)<=n){
			if(x[jjj]+1+iii<=x[n]){
			ans++;
		}
	}
}}

}
if(d==4){
	for(int iiii=2;iiii<=n/2;iiii+4){
	for(int jjjj=1;jjjj<=n;jjjj++){
		if((2+iiii)<=n){
			if(x[jjjj]+1+iiii<=x[n]){
			ans++;
		}
	}
}}

}
if(d==5){
	for(int iiiii=2;iiiii<=n/2;iiiii+5){
	for(int jjjjj=1;jjjjj<=n;jjjjj++){
		if((2+iiiii)<=n){
			if(x[jjjjj]+1+iiiii<=x[n]){
			ans++;
		}
	}
}}
}
if(d==6){
	for(int iiiiii=2;iiiiii<=n/2;iiiiii+6){
	for(int jjjjjj=1;jjjjjj<=n;jjjjjj++){
		if((2+iiiiii)<=n){
			if(x[jjjjjj]+1+iiiiii<=x[n]){
			ans++;
		}
	}
}}
}
cout<<ans;
}
}

return 0;
}
