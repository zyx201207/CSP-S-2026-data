#include<bits/stdc++.h> 
using namespace std;
struct node{
	int l;
	string a;
	bool op;
}seat[2];
int main(){	
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>seat[0].l>>seat[0].a>>seat[1].l>>seat[1].a;
    if (seat[0].a[2]=='A'||seat[0].a[2]=='B'||seat[0].a[2]=='C'){
	seat[0].op=true;
}
else{
	seat[0].op=false;
}
if (seat[1].a[2]=='A'||seat[1].a[2]=='B'||seat[1].a[2]=='C'){
	seat[1].op=true;
}
else{
	seat[1].op=false;
}
if (seat[0].l==seat[1].l){
	cout<<1;
	if (seat[0].a[0,1]==seat[0].a[0,1]){
	    cout<<1;
	    if (seat[0].op==seat[1].op){
	        cout<<1;
	        if (seat[0].a[2]+1==seat[1].a[2]||seat[0].a[2]-1==seat[1].a[2]){
	            cout<<1;
	            return 0;
				}
            else {
	            cout<<0;
	            return 0;
                 }
            }
            else {
	            cout<<"00";
	            return 0;
            }
	     }   
	else {    
	    cout<<"000";
	    return 0;
    }
	}
    else {
	    cout<<"0000";
	    return 0;
    }
}
