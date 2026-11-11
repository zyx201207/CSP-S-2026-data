#include<bits/stdc++.h>
using namespace std;

int c1,c2,a1,a2,cnt=0;
string s1,s2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1;
    cin >> c2 >> s2;
    for(int i=0;i<2;++i){
        a1=a1*10+s1[i]-'0';
        a2=a2*10+s2[i]-'0';
    }

    char t1=s1[2],t2=s2[2];
    if(c1==c2){// same chexiang
        cout << 1;

        if(a1==a2){//same pow
            cout << 1;
            if(t1-'A'+t2-'A'==5){
                cout <<"00"<<endl;
            }else if(t1-'A'+t2-'A'<5){//at A-C
                cout << 1;
                cout << (t1-'A'+t2-'A'!=2)<<endl;
            }else{//at D and F
                cout<<11<<endl;
            }


        }else{
            cout << "000"<<endl;
        }

    }else{
        cout << "0000"<<endl;
    }
}
