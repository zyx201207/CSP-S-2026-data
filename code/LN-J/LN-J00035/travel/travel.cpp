

#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    /*
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    */
    string c1,s1,c2,s2;
    bool b=0;
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    if(c1!=c2){
        cout<<0<<0<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(s1[0]==s2[0]){
        if(s1[1]==s2[1]) b=1;
    }
    cout<<b;
    if(b==0){
        cout<<0<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(s1[2]=='D')s1[2]='E';
    if(s2[2]=='D')s2[2]='E';
    if((s1[2]-'A'<3 && s2[2]-'A'>=3) || (s1[2]-'A'>=3 && s2[2]-'A'<3)){
        cout<<0<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    cout<<1;
    if(abs(s1[2]-s2[2])<2) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

