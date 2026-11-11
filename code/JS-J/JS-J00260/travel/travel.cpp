#include<bits/stdc++.h>
using namespace std;
bool a[8];
bool check1(string s1,string s2){
    bool ok1=0,ok2=0;
    if(s1[2]>='A'&&s1[2]<='C') ok1=1;
    if(s2[2]>='A'&&s2[2]<='C') ok2=1;
    if(ok1==ok2) return true;
    return false;
}
bool check2(string s1,string s2){
    int a1=s1[2]-'A';
    int a2=s2[2]-'A';
    if(abs(a1-a2)==1) return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string t1,t2;
    for(int i=0;i<=1;i++){
        t1+=s1[i];
        t2+=s2[i];
    }
    if(c1==c2) a[1]=1;
    if(t1==t2) a[2]=1;
    if(check1(s1,s2)) a[3]=1;
    if(check2(s1,s2)) a[4]=1;
    int cnt=0;
    for(int i=1;i<=4;i++){
        if(a[i]==0){
            cnt=i;
            break;
        }
        cout<<a[i];
    }
    if(cnt!=0){
        for(int i=1;i<=4-cnt+1;i++){
            cout<<0;
        }
    }
    return 0;
}
