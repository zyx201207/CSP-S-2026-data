#include<bits/stdc++.h>
using namespace std;
struct travel{
	string sum,seat;
}a,b;
char aline[3],bline[3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.sum>>a.seat>>b.sum>>b.seat;
	aline[1]=a.seat[0];
	aline[2]=a.seat[1];
	bline[1]=b.seat[0];
	bline[2]=b.seat[1];
	char aseat=a.seat[2],bseat=b.seat[2];
	bool al,bl;
	if(aseat=='A'||aseat=='C'||aseat=='B')al=true;
	else al=false;
	if(bseat=='A'||bseat=='C'||bseat=='B')bl=true;
	else bl=false;
	if(a.sum!=b.sum ){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}else{
		cout<<1;
    	if(aline[1]!=bline[1]||aline[2]!=bline[2]){
    		cout<<0;
			cout<<0;
			cout<<0;
    		return 0;
		}else{
			cout<<1;
		if(al&&bl){
			cout<<1;
			if(aseat-bseat==1||aseat-bseat==-1){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			} 
		}
		else{
			cout<<0;
			cout<<0;
			return 0;
		    } 
	    }	
	}
	return 0;
}
