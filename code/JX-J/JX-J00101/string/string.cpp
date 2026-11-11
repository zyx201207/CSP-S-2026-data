#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S,c,S1,S2;
    int n,a,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
       for(int j=1;j<=a;j++){
            S+=c;
       }
    }
   if(S.size()%2==0){
        for(int i=0;i<=S.size()/2-1;i++){
            S1+=S[i];
       }
        for(int j=S.size();j>=S.size()/2;j--){
            S2+=S[j];
       }
   }

    else{
        for(int i=0;i<=S.size()/2-1;i++){
            S1+=S[i];
       }
        for(int j=S.size();j>=S.size()/2+1;j--){
            S2+=S[j];
       }
    }

    for(int i=0;i<=S.size()/2-1;i++){
        if(S1[i]!=S2[i]){
            cnt++;
        }

    }





cout<<cnt;

    return 0;
}
