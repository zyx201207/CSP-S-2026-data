#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[5]={'A','B','C','D','F'};
    string c1,c2,s1,s2;
    int q,w;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
    }
    else if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"11";
        for(int i=0;i<5;i++){
           if(s1[2]==a[i])q=i;
           if(s2[2]==a[i])w=i;
        }
        if(((q<=2)&&(w<=2))||(q>=3&&w>=3)){
            cout<<"1";
            if(q<2&&(q+1==w||w+1==q))cout<<"1";
            else if(q=2&&q-1==w)cout<<"1";
            else if(q>3&&(q+1==w||w+1==q))cout<<"1";
            else if(q=3&&q+1==w)cout<<"1";
            else cout<<"0";

        }
        else cout<<"00";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
