#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string car1,car2;
    string sat1,sat2;
    cin>>car1>>sat1>>car2>>sat2;
    int y=sat2.size()-2;
    if(car1==car2){
        cout<<1;
        int ok=true;
        for(int i=0;i<sat1.size()-1;i++){
            if(sat1[i]!=sat2[i]){
                ok=false;
            }
        }
        int x=sat1.size()-1;
        if(ok){
            cout<<1;
            if(sat1[x]=='A' || sat1[x]=='B' || sat1[x]=='C'){
                if(sat2[x]=='A' || sat2[x]=='B' || sat2[x]<='C'){
                    cout<<1;
                    if(sat1[x]=='A' || sat1[x]=='C'){
                        if(sat2[x]=='B'){
                            cout<<1;
                        }
                        else{
                            cout<<0;
                        }
                    }
                    else{
                        cout<<1;
                    }
                }
                else{
                    cout<<0;
                    cout<<0;
                }
            }
            else{
                if(sat2[x]=='D' || sat2[x]=='F'){
                    cout<<1<<1;
                }
                else{
                    cout<<0<<0;
                }
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
