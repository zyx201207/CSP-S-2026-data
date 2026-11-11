#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
string c1, s1, c2, s2;
bool tyc(){
    if(s1[2]=='A'&&s2[2]=='B'){
        return 1;
    }else if(s1[2]=='A'&&s2[2]=='C'){
        return 1;
    }else if(s1[2]=='B'&&s2[2]=='A'){
        return 1;
    }else if(s1[2]=='B'&&s2[2]=='C'){
        return 1;
    }else if(s1[2]=='C'&&s2[2]=='A'){
        return 1;
    }else if(s1[2]=='C'&&s2[2]=='B'){
        return 1;
    }else if(s1[2]=='D'&&s2[2]=='F'){
        return 1;
    }else if(s1[2]=='F'&&s2[2]=='D'){
        return 1;
    }else{
        return 0;
    }
}
bool xl(){
    if(s1[2]=='A'&&s2[2]=='B'){
        return 1;
    }else if(s1[2]=='B'&&s2[2]=='A'){
        return 1;
    }else if(s1[2]=='C'&&s2[2]=='B'){
        return 1;
    }else if(s1[2]=='B'&&s2[2]=='C'){
        return 1;
    }else if(s1[2]=='D'&&s2[2]=='F'){
        return 1;
    }else if(s1[2]=='F'&&s2[2]=='D'){
        return 1;
    }else{
        return 0;
    }
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<s1<<c2<<s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000"<<endl;
        return 0;
    }
    int sum=0;
    int len=s1.size()-1;
    //cout<<len<<endl;
    for(int i=0;i<len;i++){
        if(s1[i]==s2[i]){
            sum+=1;
        }
    }
    //cout<<sum<<endl;
    if(sum==2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(sum==2&&tyc()){
        cout<<1;
    }else{
        cout<<0;
    }
    if(sum==2&&tyc()&&xl()){
        cout<<1;
    }else{
        cout<<0;
    }
    cout<<endl;
    return 0;
}
