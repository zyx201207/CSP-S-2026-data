#include<bits/stdc++.h>
using namespace std;



int main(){
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
    int n1,n2;
    char m1,m2;
    int a,b;
    scanf("%d %d%c %d %d%c",&a,&n1,&m1,&b,&n2,&m2);
    if(a==b){
        cout<<1;
        if(n1=n2){
            cout<<1;
            if(m1=='A'||m1=='B'||m1=='C'){
                if(m2=='A'||m2=='B'||m2=='C'){
                    cout<<1;
                        if(min(m1,m2)+1==(m1,m2))cout<<1;
                            else cout<<0;
                    }
                    else cout<<"00";


            }
            else if(m1=='D'||m1=='F'){
                if(m2=='D'||m2=='F'){
                    cout<<1;
                    cout<<1;
                }
                else cout<<"00";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;

}
