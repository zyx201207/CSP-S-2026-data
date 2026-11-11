#include<bits/stdc++.h>
using namespace std;
string pa,pb,pc,pd;
int p1b,p2d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("treval.out","w",stdout);
    cin>>pa>>pb>>pc>>pd;
    if(pa==pc){
        cout<<1;
        if(pb[0]==pd[0]||pb[1]==pd[1]){
            cout<<1;
            p1b=pb[2]-'A';
            p2d=pd[2]-'A';
            if((p1b<3&&p2d<3)||((p1b==3&&p2d==5)||(p1b==5&&p2d==3))){
                cout<<1;
                if(p1b-p2d==1||p2d-p1b==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
