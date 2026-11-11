#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool gzy[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        gzy[1]=true;
        if (s1[0]==s2[0]&&s2[1]==s1[1]){
            gzy[2]=true;
            char a=s1[2],b=s2[2];
            if (a=='A'){
                if(b=='B'){
                    gzy[3]=true;
                    gzy[4]=true;
                }
                if (b=='C'){
                    gzy[3]=true;
                }
            }
            else if (a=='B'){
                if (b=='C' || b=='A'){
                    gzy[3]=true;
                    gzy[4]=true;
                }
            }
            else if (a=='C'){
                if(b=='B'){
                    gzy[3]=true;
                    gzy[4]=true;
                }
                if (b=='A'){
                    gzy[3]=true;
                }
            }
            else if (a=='D'&& b=='F'){
                gzy[3]=true;
                gzy[4]=true;
            }
            else if (a=='F'&& b=='D'){
                gzy[3]=true;
                gzy[4]=true;
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<gzy[i];
        }
    return 0;
}
