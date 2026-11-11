#include<bits/stdc++.h>
using namespace std;
int card[555555]={0};
int ju[555555]={0};
int ans[555555]={0};
int main(){

     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int num=1;num<=n;num++){
            int l=1;
        for(int i=num;i<=n;i++){
          //  ju[l]=card[i];l++;

            for(int j=i;j<=n;j++){
                if(card[j]==card[i]){
                   i=j;
                }
            }

            ju[l]=card[i];l++;
        }
        for(int q=1;q<l;q++){
            ans[ju[q]]++;
            ju[q]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

// 10 3 3 1 2 1 3 2 3 1 2 1


