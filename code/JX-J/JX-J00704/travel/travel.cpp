#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    map<char,int> mp;
    mp['A']=1;
    mp['B']=1;
    mp['C']=1;
    mp['D']=2;
    mp['E']=2;
    int cnt=0;
    if(c1==c2){
        cout<<1;
        cnt++;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            cnt++;
            if(mp[s1[2]]==mp[s2[2]]){
                cnt++;
                cout<<1;
                if(min(int(s2[2]),int(s1[2]))+1==max(int(s2[2]),int(s1[2]))){
                    cout<<1;
                    cnt++;
                }

            }

        }

    }
    for(int i=1;i<=4-cnt;i++)cout<<0;
    return 0;
}
