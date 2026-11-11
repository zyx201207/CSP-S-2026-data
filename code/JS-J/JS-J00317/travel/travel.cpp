#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int rc,rp,xc,xp;//c:chexanghao;p:pai;s:zuowei
    char rs,xs;
    cin>>rc>>rp>>rs>>xc>>xp>>xs;
    if(rc==xc){
		cout<<1;
		if(rp==xp){
			cout<<1;
			if((rs<='C' && xs<='C')||(rs>'C' && xs>'C')){
				cout<<1;
				if(abs(int(rs-xs))==1){
					cout<<1;
				}else{
					cout<<0;
				}
            }else{
				cout<<"00";
			}
	    }else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
