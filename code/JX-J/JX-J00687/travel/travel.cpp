#include<bits/stdc++.h>
using namespace std;
int a,b,ca,cb;
string as,bs;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>as>>b>>bs;
    //cin>>as>>bs;
    int aa,bb;
    aa=(as[0]-'0')*10+(as[1]-'0');
    ca=(as[2]-'A'+1);
    bb=(bs[0]-'0')*10+(bs[1]-'0');
    cb=(bs[2]-'A'+1);
    //cout<<aa<<" "<<bb<<" "<<ca<<" "<<cb;
    if(a==b){
        cout<<1;
        if(aa==bb){
			cout<<1;
			if((ca<=3&&cb<=3)||(ca>=4&&cb>=4)){
				cout<<1;
				//cout<<" "<<ca<<" "<<cb<<" ";
				//cout<<999;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0<<0;
		}
		if((ca<=3&&cb<=3)||(ca>=4&&cb>=4)){
			if(aa==bb){
				if(ca-cb==1||cb-ca==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(ca==cb){
				if(aa-bb==1||bb-aa==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
    }	
    		

    else{
		cout<<0<<0<<0<<0;
	}
    return 0;
}
