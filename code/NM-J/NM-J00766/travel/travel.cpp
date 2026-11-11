#include<bits/stdc++.h>
using namespace std;
struct node{
    string c;
    string s;
}R,X;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>R.c>>R.s;
    cin>>X.c>>X.s;
    string answer="";
    if(R.c==X.c){
        if(R.s[0]==X.s[0] && R.s[1]==X.s[1]){
            if(R.s[2] <= 'C' && X.s[2] <= 'C'){
                if(abs((int)R.s[2]-(int)X.s[2]) == 1)
                    answer="1111";
                else
                    answer+="1110";
            }
            else if(R.s[2] > 'C' && X.s[2] > 'C'){
                if(abs((int)R.s[2]-(int)X.s[2]) == 2)
                    answer+="1111";
                else
                    answer+="1110";
            }
            else{
                answer="1100";
            }
        }
        else{
            answer="1000";
        }
    }
    else{
        answer="0000";
    }
    cout<<answer;
    return 0;
}
