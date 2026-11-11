#include<bits/stdc++.h>
using namespace std;

long long a[500005],b[300005]={},c[300005]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=a[j];
            if(b[x]==0){
                b[x]++;
            }
            else{
                c[x]++;
                for(int s=1;s<=m;s++){
                    b[s]--;
                }
            }
        }

    }
    for(int i=1;i<=m;i++){
       cout << c[i] <<" ";
    }

    return 0;
}

