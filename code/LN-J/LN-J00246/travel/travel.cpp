#include<bits/stdc++.h>
using namespace std;
int sum,res;
bool ans,ans2,ans3,ans4;
string c1,c2,c3,c4;
int main(){
    freopen("travel.in","r",stdin);
      freopen("travel.out","w",stdout);

    cin>>c1>>c2>>c3>>c4;
    for(int i=0;i<2;i++){
        if(c1[i]==c3[i]){
            res++;
        }
    }

    if(res==2){
        ans=true;
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    for(int i=0;i<2;i++){
        if(c2[i]==c4[i]){
            sum++;
        }

    }
    if(sum==2&&ans){
        ans2=true;
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(c2[2]<='C'&&c2[2]>='A'&&ans2&&c4[2]<='C'&&c4[2]>='A'){
            ans3=true;
        cout<<"1";
    }
    else if(c2[2]<='F'&&c2[2]>='D'&&ans2&&c4[2]<='F'&&c4[2]>='D'){
        ans3=true;
        cout<<"1";
    }
    else {
        cout<<"0";
    }
    if(ans3&&abs(c2[2]-c4[2])==1){
        cout<<"1";
    }
    else if(ans3&&c2[2]=='D'&&c4[2]=='F'){
        cout<<"1";
    }
    else if(ans3&&c2[2]=='F'&&c4[2]=='D'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

    return 0;
}
