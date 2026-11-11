#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans1,ans2,ans3,ans4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    ans1=0,ans2=0,ans3=0,ans4=0;
    if(c1==c2){
        ans1=1;
    }
    string row1=s1.substr(0,2);
    string row2=s2.substr(0,2);
    if(c1==c2&&row1==row2){
        ans2=1;
    }
    char seat1=s1[2];
    char seat2=s2[2];
    if(c1==c2&&row1[0]==row2[0]&&row1[1]==row2[1]){
        if(seat1=='A'){
            if(seat2=='B'||seat2=='C'){
                ans3=1;
            }
        }
        if(seat1=='B'){
            if(seat2=='A'||seat2=='C'){
                ans3=1;
            }
        }
        if(seat1=='C'){
            if(seat2=='A'||seat2=='B'){
                ans3=1;
            }
        }
        if(seat1=='D'){
            if(seat2=='F'){
                ans3=1;
            }
        }
        if(seat1=='F'){
            if(seat2=='D'){
                ans3=1;
            }
        }
    }
    if(c1==c2&&row1[0]==row2[0]&&row1[1]==row2[1]){
        if(seat1=='A'){
            if(seat2=='B'){
                ans4=1;
            }
        }
        if(seat1=='B'){
            if(seat2=='A'||seat2=='C'){
                ans4=1;
            }
        }
        if(seat1=='C'){
            if(seat2=='B'){
                ans4=1;
            }
        }
        if(seat1=='D'){
            if(seat2=='F'){
                ans4=1;
            }
        }
        if(seat1=='F'){
            if(seat2=='D'){
                ans4=1;
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
}
