#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1 == c3){
        if(c2[0] == c4[0] && c2[1] == c4[1]){
            if(!((c2[2] >= 'A' && c2[2] <= 'C')^(c4[2] >= 'A' && c4[2] <= 'C'))){
                if(c2[2]+1 == c4[2] && c2[2] != 'C'){
                    cout<<"1111";
                }else if(c4[2]+1 == c2[2] && c4[2] != 'C'){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
