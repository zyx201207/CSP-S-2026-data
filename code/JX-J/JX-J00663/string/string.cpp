#include<bits/stdc++.h>
using namespace std;
struct kl{
    long long x;
    string y;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    kl b[200005];
    long long a,sum=0,t=1,w=0,l=0;
    string n;
    cin>>a;
    w=a;
    for(int i=1;i<=a;i++){
        cin>>b[i].x;
        cin>>b[i].y;
    }
    while(true){
        if(t==w||t>a/2){
            break;
        }
        if(b[t].y==b[w].y){
            if(b[t].x>=b[w].x){
            b[t].x-=b[w].x;
                if(b[t].x==0){
                    t++;
                }
                w--;
            }
            else{
                b[w].x-=b[t].x;
                t++;
            }
        }
        else{
            if(b[t].x>=b[w].x){
                sum+=b[w].x;
                b[t].x-=b[w].x;
                if(b[t].x==0){
                    t++;
                }
                w--;
            }
            else{
                sum+=b[t].x;
                b[w].x-=b[t].x;
                t++;
            }
        }
    }
    cout<<sum;
    return 0;
}
