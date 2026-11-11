#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main(){
    int n,m;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[500000];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int s;
    sort(a[0],a[n-1]);
    a[0]=s;
    for(int z=0;z<n+1;z++){
        a[z]=a[z+1];
    }
    a[n-1]=s;
    int h[100000];
    for(int e=0;e<n;e++){
        for(int q=0;q<n;q++){
            if(a[e]==a[q+1]){
                if(m<0){
                    continue;
                }
                    else {
                      h[e]++;
                    }
            }
            else{
                m-=(a[q+1]-=a[e]);
                if(m<0){
                    continue;
                }
                    else {
                      h[e]++;
                    }
            }
        }
    }
    for (int r=0;r<n;r++){
      if(h[r+1]>=h[0]){
          h[0]=h[r+1];
        }
    }
    if(h[0]>=1){
        cout<<h[0]+1;
    }
    else{
        cout<<h[0];
    }
    return 0;
}
