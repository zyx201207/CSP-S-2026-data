#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,d="ABCDF";
    int a=0,b=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && ((s1[2]>=d[3] && s2[2]>=d[3]) || (s1[2]<d[3] && s2[2]<d[3]))){
            cout<<1;
            a=1;
    }
    else cout<<0;
    if(a==1){
        for(int i=0;i<5;i++){
            if((d[i]==s1[2] || d[i]==s2[2]) && (d[i+1]==s1[2] || d[i+1]==s2[2])){
                cout<<1;
                b=1;
        }
        }
        if(b==0) cout<<0;}
    if(a==0) cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
