#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
void rule(int num[],int len){
    int k[300005],ans=1;
    k[0] = num[0];
    for(int i=1;i<len;i++){
        for(int j=0;j<ans;j++){
            if(num[i]==k[j]){
                for(int f=j+1;f<=ans;f++) k[f]=0;
                ans = j;
                break;
            }
        }
        k[ans]=num[i];
        ans++;
    }
    for(int i=0;i<ans;i++){
            b[k[i]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int x[300005],t=0;
        for(int j=i;j<n;j++){
            x[t] = a[j];
            t++;
        }
        rule(x,t);
    }
    for(int i=1;i<=m;i++) cout << b[i] << ' ';


    return 0;
}
