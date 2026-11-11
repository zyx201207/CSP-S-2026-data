#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    string s1,s2,s3,s4;
    cin>>a>>s1>>b>>s2;
    if(a==b) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=1;i++){
        s3[i]=s1[i];
    }
    for(int i=0;i<=1;i++){
        s4[i]=s2[i];
    }
    int q=0,w=0;
    for(int i=0;i<=1;i++){
        if(i==0){
            q+=(s3[i]-'0')*10;
            w+=(s4[i]-'0')*10;
        }else{
            q+=s3[i];
            w+=s4[i];
        }
    }
    if(q==w) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    int n=s1.size(),m=s2.size();
    if(s1[n-1]>='A'&&s1[n-1]<='C'&&s2[m-1]>='A'&&s2[m-1]<='C'||s1[n-1]=='D'&&s2[m-1]=='F'||s1[n-1]=='F'&&s2[m-1]=='D') cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(s1[n-1]>='A'&&s1[n-1]<='C'&&s2[m-1]>='A'&&s2[m-1]<='C'){
        if(s1[n-1]=='A'&&s2[m-1]=='B'){
            cout<<1;
            return 0;
        }else if(s1[n-1]=='"B'&&s2[m-1]=='A'||s2[m-1]=='C'){
            cout<<1;
            return 0;
        }else if(s1[n-1]=='C'&&s2[m-1]=='B'){
            cout<<1;
            return 0;
        }
    }else if(s1[n-1]=='D'&&s2[m-1]=='F'||s1[n-1]=='F'&&s2[m-1]=='D'){
        cout<<1;
    }
    cout<<"0";
    return 0;
}
