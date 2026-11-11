#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string z1,z2,ch1,ch2;
    cin>>ch1>>z1>>ch2>>z2;
    if(ch1==ch2){
        cout<<1;
        int p1=0,p2=0;
        for(int i=0;i<2;i++){
            p1=p1*10+(z1[i]-'0');
            p2=p2*10+(z2[i]-'0');
        }
        if(p1==p2){
            cout<<1;
            char w1=z1[2],w2=z2[2];
            if((w1<'D' && w2<'D') || (w1>='D' && w2>='D')){
                cout<<1;
                if(abs(int(w1-w2))==1){
                    cout<<1;
                }
                else{
                	cout<<'0';
				}
            }
            else{
            	cout<<"00";
			}
        }
        else{
        	cout<<"000";
		}
    }
    else{
    	cout<<"0000";
	}
    return 0;
}
