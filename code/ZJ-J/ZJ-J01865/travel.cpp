#include<bits/stdc++.h>
using namespace std;
string l = "ABC",r = "CD";
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("trave.in","r",stdin);
    freopen("trave.out","w",stdout);
    string cone,sone,ctwo,stwo;
    cin>>cone>>sone>>ctwo>>stwo;
    vector<int> ans(4,0);
    if(cone == ctwo){
        ans[0]=1;
    }
    if (sone[0] == stwo[0] && sone[1] == stwo[1]){
        ans[1]=1;
    }
    char a = sone[2],b=stwo[2];
    if (ans[1]){
        bitset<2> is_in_A,is_in_B;
        for (char ch:l){
            if (ch == a){
                is_in_A[0] = 1;
            }else if(ch==b){
                is_in_A[1] = 1;
            }
        }
        if (is_in_A.count() == 2){
            ans[2]=1;
        }
        for (char ch:r){
            if (ch == a){
                is_in_B[0] = 1;
            }else if(ch==b){
                is_in_B[1] = 1;
            }
        }
        if (is_in_B.count() == 2){
            ans[2]=1;
        }

    }
    if (ans[2]){
        if ((sone[2]-'A'+1 == stwo[2]-'A')||(sone[2]-'A'-1 == stwo[2]-'A')){

            ans[3]=1;
        }
    }
    for (int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
