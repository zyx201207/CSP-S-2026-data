#include<bits/stdc++.h>
using namespace std;
char cx1[2];
char hao1[3];
char cx2[2];
char hao2[3];
char q;
int main(){

  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);

    for(int i=0;i<2;i++)
        cin>>cx1[i];//cin>>q;
    for(int i=0;i<3;i++)
        cin>>hao1[i];//cin>>q;
    for(int i=0;i<2;i++)
        cin>>cx2[i];//cin>>q;
    for(int i=0;i<3;i++)
        cin>>hao2[i];//cin>>q;
    if(cx1[0]!=cx2[0]||cx1[1]!=cx2[1]){
        cout<<"0000";
        return 0;
    }
    cout<<"1";

    if(hao1[1] != hao2[1]||hao1[0] != hao2[0]){
        cout<<"000";
        return 0;
    }
    cout<<"1";

    if(((hao1[2] == 'A'||hao1[2] == 'B'||hao1[2] == 'C')&&(hao2[2] == 'A'||hao2[2] == 'B'||hao2[2] == 'C'))||((hao1[2] == 'D'||hao1[2] == 'F')&&(hao2[2] == 'D'||hao2[2] == 'F'))){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if((hao1[2]=='A'&&hao2[2]=='C')||(hao1[2]=='C'&&hao2[2]=='A')){
        cout<<"0";
    }else
    cout<<"1";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
