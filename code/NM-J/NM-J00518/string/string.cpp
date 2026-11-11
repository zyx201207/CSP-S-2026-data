#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);  //记得及时解除注释！
    freopen("string.out","w",stdout);  //记得及时解除注释！
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nst,chrt=0,cnta=0;
    cin>>nst;
    string para;string rev;
    for(int i=0;i<nst;i++){
        int ch;char chr;
        cin >> ch >> chr;
        for(int j=0;j<ch;j++){
            chrt++;
            para+=chr;
        }
        
    }
    for(int k=para.size()-1;k>=0;k--){
        rev+=para[k];}
    if(rev==para){
        cout << 0;
    }else{
        for(int y=0;y<rev.size()/2;y++){
            if(rev[y]!=rev[rev.size()-y-1]){
                rev[y]=rev[rev.size()-y-1];
                cnta++;
            }
        }
        cout << cnta << endl;
    }
    return 0;
}
