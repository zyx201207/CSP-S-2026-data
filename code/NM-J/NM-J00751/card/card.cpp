#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], num[300005], b[500005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=m; i++){
        for(int w=1; w<=n; w++){
        b[w] = a[w];
        }
        for(int j=i; j<=n; j++){
            for(int s=i; s<=j; s++){
                if(b[s]==b[j]){
                    for(int x=s; x<=j-1; x++){
                        b[x] = 0;
                    }
                }
            }
        }
        for(int y=i; y<=n; y++){
            num[b[y]]++;
        }
    }
    for(int i=1; i<=m; i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
