#include<bits/stdc++.h>
using namespace std;
int n,m,head=0;
struct Stu{
    int a,b,num;
};
Stu x[500005];
int y[500005];
//i=game's times
void A(int i){
    bool aa[500005];
    for(int j=i;j<=n;j++){
        if(aa[j]==true)continue;
        for(int k=j+1;k<=n;k++){
            if(x[k].num==x[j].num&&aa[j]==false){
                for(int l=j;l<k;l++){
                    aa[l]=true;
                }
            }
        }
    }
    for(int j=i;j<=n;j++){
       if(aa[j]==false){
        y[]
       }
    }
}

int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>x[1].num;
    head=1;
    x[1].b=0;
    for(int i=2;i<=n;i++){
        cin>>x[i].num;
    }for(int i=1;i<=n;i++){
        A(i);
    }
}//b< A >a
