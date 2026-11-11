#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,char> >s(n+5);
    long long pt=0;
    for(int i=1;i<=n;i++){
        cin>>s[i].first>>s[i].second;
    }
    int l=1,r=n;
    while(l<r){
        bool t=s[l].first>s[r].first;
        bool p=s[l].second==s[r].second;
        if(p){
            if(t){
                s[l].first-=s[r].first;
                r--;
            }else{
                s[r].first-=s[l].first;
                l++;
                if(s[r].first==0){
                    r--;
                }
            }
        }else{
            if(t){
                s[l].first-=s[r].first;
                pt+=s[r].first;
                r--;
            }else{
                s[r].first-=s[l].first;
                l++;
                pt+=s[l-1].first;
                if(s[r].first==0){
                    r--;
                }
            }
        }
    }
    cout<<pt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
