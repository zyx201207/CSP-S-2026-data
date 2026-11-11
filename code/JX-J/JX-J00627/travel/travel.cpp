#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>a2>>b1>>b2;
    string a,b,c,d,e,f;
    a=a2[0];
    b=a2[1];
    c=a2[2];
    d=b2[0];
    e=b2[1];
    f=b2[2];
    int cnt=0;
    if(a1==b1){
        cout<<1;
        cnt++;
        if(a==d&&b==e){
            cout<<1;
            cnt++;
            if(c=="A"||c=="B"||c=="C"){
                if(f=="A"||f=="B"||f=="C"){
                    cout<<1;
                    cnt++;
                    if(c=="A"&&f=="B"){
                        cout<<1;
                        cnt++;
                    }
                    if(c=="B"&&f=="A"){
                        cout<<1;
                        cnt++;
                    }
                    if(c=="B"&&f=="C"){
                        cout<<1;
                        cnt++;
                    }
                    if(c=="C"&&f=="B"){
                        cout<<1;
                        cnt++;
                    }
                    else{
                        cout<<0;
                        cnt++;
                    }
                }
            }

            else if(c=="D"&&f=="F"){
                cout<<11;
                cnt+=2;
            }
            else if(c=="F"&&f=="D"){
                cout<<11;
                cnt+=2;
            }
        }
    }
    else{
        for(int i =0;i<4;i++){
            cout<<0;

        }
        cnt=4;
    }
    for(int i=4-cnt;i>0;i--)
    {

        cout<<0;
    }
    return 0;

}
