#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1;
    cin>>c2>>s2;
    //cout<<c2;
    mp['A']=mp['B']=mp['C']=1;
    mp['D']=mp['F']=2;
    set<pair<char,char>>st;
    st.insert({'A','B'});
    st.insert({'B','A'});
    st.insert({'B','C'});
    st.insert({'C','B'});
    st.insert({'D','F'});
    st.insert({'F','D'});
    //cout<<c1<<' '<<s1<<' '<<c2<<' '<<s2<<' ';
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(mp[s1[2]]==mp[s2[2]]){
                cout<<1;
                if(st.count({s1[2],s2[2]})){
                   cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else{
        cout<<"0000";
    }

    return 0;
}
