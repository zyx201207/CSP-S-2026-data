#include<bits/stdc++.h>
using namespace std;
int b[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,s;
    cin>>n>>s;
    int a[n],num[s+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int p=i;p<n;p++){
            b[p]=a[p];
            int t=i;
            while(t<p){
                if(b[p]==a[t]){
                    for(int j=t;j<p;j++){
                        b[j]==0;
                    }
                }
                t++;
            }
        }
        for(int d=0;d<n;d++){
            num[b[d]]++;
        }
    }
    for(int i=1;i<=s;i++){
        cout<<num[i]<<" ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
