#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=0;
    string s,S;
    bool ish;
    cin >> n;
    for(int i=1;i<=n;i++){
        int j;
        cin >> j >> s;
        for(int k=1;k<=j;k++) S+=s;
    }
    //panduan
    if((S.size()%2)!=0){
        for(int i=0;i<S.size()/2;i++){
            for(int k=S.size()-1;k>S.size()/2;k--)
            if(S[i] == S[k]) ish = 1;
            else ish = 0;
        }
    }
    else{
        for(int i=0;i<=S.size()/2;i++){
            for(int k=S.size()-1;k>=S.size()/2;k--)
            if(S[i] == S[k]) ish = 1;
            else ish = 0;
        }
    }
    //gai
    if(!ish){
        //for(int i=0;i<S.size()/2;i++){
            //for(int k=S.size()-1;k>S.size()/2;k--)
            //if(S[i] != S[k]) c++;
      //  }
        //cout << c/(S.size()/2);
        if((S.size()%2)!=0){
            for(int i=0;i<S.size()/2;i++){
                for(int k=S.size()-1;k>S.size()/2;k--)
                if(S[i] != S[k]) c++;
            }
        }
        else{
            for(int i=0;i<=S.size()/2;i++){
                for(int k=S.size()-1;k>=S.size()/2;k--)
                if(S[i] != S[k]) c++;
            }
        }
        cout << c/(S.size()/2);
    }
    else cout << 0;
    return 0;
}
