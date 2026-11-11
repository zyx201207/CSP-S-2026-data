include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[3],s2[3];
int main(){
    foropen(travel.in,"w",stdin);
    foropen(travel.out,"r",stdout);
    cin>>c1;
    for(int i=0;i<3;i++){
        cin>>s1[i];
    }cin>>c2;
    for(int i=0;i<3;i++){
        cin>>s2[i];
    }
    if(c1!=c2){
        cout<<"0000";
    }if else(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000"
    }if else(s1[2]<=67&&s2[2]<=67||s1[2]>67&&s2[2]>67){
        if(s1[2]-s2[2]==1||s1[2]-s2[2]==1){
            cout << "1111";
        }else{
            cout<<"1110"
        }
    }
    else cout<<"1100";
}

