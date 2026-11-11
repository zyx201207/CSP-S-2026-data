#include<bits/stdc++.h>
using namespace std;
int cx_a,cx_b;
string aa,bb;
int k=0,m=0,n=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    cin>>cx_a>>aa>>cx_b>>bb;

    if(cx_a==cx_b){
        cout<<1;
        m=1;
    }
    else{
        cout<<0;
    }

    if(m==1){
        if(cx_a==cx_b&&aa[0]==bb[0]&&aa[1]==bb[1]){
            cout<<1;
            n=1;
        }
        else{
            cout<<0;
        }
    }else{
        cout<<0;
    }

    if(n==1){
        if(aa[2]=='A'||aa[2]=='B'||aa[2]=='C'){
            if(bb[2]=='A'||bb[2]=='B'||bb[2]=='C'){
                cout<<1;
                k=1;
            }
            else{
                cout<<0;
            }
        }else if(aa[2]=='D'||aa[2]=='F'){
            if(bb[2]=='D'||bb[2]=='F'){
                cout<<1;
                k=1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0;
    }


    if(k==1){
        if(aa[2]=='A'){
            if(bb[2]=='B'){
                cout<<1;
            }else{
                cout<<0;
            }

        }else if(aa[2]=='B'){
            if(bb[2]=='A'||bb[2]=='C'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else if(aa[2]=='C'){
            if(bb[2]=='B'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else if(aa[2]=='D'){
            if(bb[2]=='F'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else if(aa[2]=='F'){
            if(bb[2]=='D'){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0;
    }






    return 0;
}
