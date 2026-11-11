#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S,SS;
    int n,cishu=0,sum=0,samenum=0;
    cin>>n;
    int num[10010];
    char charr[10010];
    for(int i=0;i<=n+1;i++){
        string xhang;
        cin>>xhang;
        num[i]=xhang[0];
        charr[i]=xhang[2];
        for(int j=cishu;i<num[i];j++){
            S[j]=charr[i];
            cishu++;
        }
    }
    for(int i=0;i<S.size()/2;i++){
        SS[i]=S[i];
    }
    for(int i=S.size();i>S.size()/2;i--){
        if(S[i]==SS[sum]){
            samenum++;
        }
        sum++;
    }
    if(samenum==S.size()/2&&samenum!=0){
       cout<<"0";
       return 0;
    }
    cout<<S.size()/2-samenum;
    return 0;
}
//a (a) b b (c)
//a (b) b b (a)

