#include<bits/stdc++.h>
using namespace std;
bool c1(char a,char b){
	if(a=='A'&&b=='B'){
		return true;
	}else if(a=='B'&&b=='A'){
		return true;
	}else if(a=='B'&&b=='C'){
		return true;
	}else if(a=='C'&&b=='B'){
		return true;
	}else if(a=='A'&&b=='C'){
		return true;
	}else if(a=='C'&&b=='B'){
		return true;
	}else if(a=='D'&&b=='E'){
		return true;
	}else if(a=='E'&&b=='D'){
		return true;
	}
	return false;
}
bool c2(string a,string b){
	if(a=="A"&&b=="B"){
		return true;
	}else if(a=="B"&&b=="A"){
		return true;
	}else if(a=="B"&&b=="C"){
		return true;
	}else if(a=="C"&&b=="B"){
		return true;
	}else if(a=="D"&&b=="E"){
		return true;
	}else if(a=="E"&&b=="D"){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	char a=s1[2];
	char b=s2[2];
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	    if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='B'&&b=='C'){
		cout<<1;
		if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='C'&&b=='B'){
		cout<<1;
		if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='A'&&b=='C'){
		cout<<1;
		if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='C'&&b=='A'){
		cout<<1;
		if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='D'&&b=='E'){
		cout<<1;
		if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
}
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	    if(a=='A'&&b=='B'){
		cout<<1;
		    if(a=='A'&&b=='B'){
		cout<<1;
	}else if(a=='B'&&b=='A'){
	    cout<<1;
	}else if(a=='B'&&b=='C'){
		cout<<1;
	}else if(a=='C'&&b=='B'){
		cout<<1;
	}else if(a=='D'&&b=='E'){
		cout<<1;
	}else if(a=='E'&&b=='D'){
	    cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	}else{
		cout<<0<<0;
		return 0;
	}
	}else{
		cout<<0<<0<<0; 
	}

	return 0;
} 
