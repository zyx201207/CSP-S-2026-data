#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int num = 0;
    for(int i = 1;i<=t;i++){
        long long n,d;
        cin>>n>>d;
        long long island[3000000];
        for(int j = 0;j<n;i++){
            cin>>island[i];
        }
        for(int l = 0;l<n;l++){
            for(int r = l;r<n;r++){
                if(r==l){
                   continue;
                }
                int longnow = 0;
                for(int p = 1;p<=d;p++){
                    for(int g = l;g<=r;g++){
                        if(island[l]+p==island[g]){
                            longnow++;

                        }
                    }
                }
            }
        }
    }
    return 0;
}

