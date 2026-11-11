#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300005],b[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
long long bsum=0;
bool panduan=0;
map<int,int>mp;
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){

        for(int k=1;k<=bsum;k++){
            if(b[k]==a[j]){
                for(int h=k;h<=bsum;h++){
                    b[h]=0;
                }
                bsum=k;
                b[bsum]=a[j];
                panduan=1;
                break;
            }
        }
        if(panduan==0){
        bsum++;
        b[bsum]=a[j];
        }
        panduan=0;
    }
    for(int l=1;l<=bsum;l++){
        mp[b[l]]++;
    }
}
for(int i=1;i<=m;i++){
    cout<<mp[i]<<" ";
}
return 0;
}
