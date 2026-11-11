#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long zongshu=0;
    long long jiadian=0;
    long long G=0;
    long long B=0;
    long long jieguo=0;
    cin>>zongshu;
    cin>>jiadian;
    long long nengliang[zongshu];
    for(int a=0;a<zongshu;a++){
        cin>>nengliang[a];
    }
    for(int i=0;i<zongshu;i++){
        for(int j=0;j<i;j++){
          if(nengliang[i]<nengliang[j]){
            B=nengliang[j];
            nengliang[j]=nengliang[i];
            nengliang[i]=B;
          }
          B==0;
        }
    }
    for(int c=0;c<zongshu;c++){
        jiadian=jiadian+nengliang[c];
        G=jiadian/(c+1);
        if(G==nengliang[c]){
            jieguo=c+1;
            for(int a=c+1;a<zongshu;a++){
                if(nengliang[a]==G){
                    jieguo++;
                }
            }
            cout<<jieguo;
            return 0;
        }
    }
    return 0;
}
