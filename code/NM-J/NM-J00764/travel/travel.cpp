#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("strvel.in","r",stdin);
	freopen("strvel.out","w",stdout);
 string a,c;
char b,d;
cin>>a>>b>>c>>d;
if(a==c){
	cout<<"1";

}else{
	cout<<"0";
}
if(b==d){
	cout<<"1";
}else{
	cout<<"0";
}
if(b=='A'&&b=='B'&&b=='C'||d=='A'&&d=='B'&&b=='C'){
	cout<<"1";
}else{
	cout<<"0";
}
if(b=='A'||d=='B'&&b=='B'||d=='A'&&b=='C'||d=='B'&&b=='B'||d=='C'&&b=='F'||d=='D'&&b=='D'||d=='F'){
	cout<<"1";
}else{
	cout<<"0";
}
    return 0;
}
