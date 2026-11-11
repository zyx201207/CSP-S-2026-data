#include <bits/stdc++.h>
using namespace std;

int main (){
    int m,n;
    cin>>m>>n;
    int cnt[m+1];
    for(int i=1;i<=m;i++){
        cnt[i]=0;
    }
    int b[1225];
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }

    for (int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){
            for(int k=j;k>b[j];k--){
                if(b[k]==b[j]){
                    for(int num=k;num<j;num++){
                        b[num]=0;

                }
            }
        }
        for(int j=i;j<=n;j++){
            cnt[b[j]]++;

        }
        }
    }

    for(int i=1;i<=n;i++){
        cout <<cnt[i]<<" ";
    }
    return 0;
}
