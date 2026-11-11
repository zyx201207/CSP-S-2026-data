#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
const int N=5000000005;
const int M=5000005;
const int S=20005;
const int T=1005;
const int K=105;
//division
struct node{
    string which;
    string where;
};
node a,b;
//division
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //division
    cin>>a.where>>a.which>>b.where>>b.which;
    if(a.where==b.where){
        string s1=a.which,s2=b.which;
        char ans1=s1[0];
        char ans2=s2[0];
        //65 66 67 68 70
        if(ans1+s1[1]==ans2+s2[1]){
            if((s1[2]>='D' && s2[2]>='D') || (s1[2]<'D' && s2[2]<'D')){
                if(abs((int)s1[2]-(int)s2[2])==1 || abs((int)s1[2]-(int)s2[2])==2) cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    //division
    ///*
    cout.flush();
    cout<<flush;
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    //*/
    return 0;
}
