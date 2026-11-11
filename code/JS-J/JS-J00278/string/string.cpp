#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long zh,x=0,n,ln=0,cnt;
    vector<int> Len,letter;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>Len[i]>>letter[i];
        ln+=Len[i];
    }
    zh=ln/2;
    for(int le=0;le<Len.size();le++){
        if(x+Len[i]<=zh){
            x+=Len[i];
            int ri,j;
            for(j=le;ri<x;j++){
                ri+=Len[Len.size()-j];
            }
            int tmp=ri-x;
            for(int i=le;i<=j;i++){
                if
            }
        }
    }
    return 0;

}
