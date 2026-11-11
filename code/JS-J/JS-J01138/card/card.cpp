#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> card(n);
    for(long long i=0;i<n;i++){
        cin>>card[i];
    }
    vector<long long> ans(m,0);
    for(long long i=0;i<n;i++){
        vector<long long> a(m+1,-1);
        vector<long long> v(1000000,0);
        long long j=0;
        for(long long s=i;s<n;s++){
            long long k=card[s];
            if(a[k]!=-1){
                for(long long x=a[k]+1;x<j;x++){
                    a[v[x]]=-1;
                }
                j=a[k];
                j++;
            }
            else{
                v[j]=k;
                a[k]=j;
                j++;
            }
        }
        for(long long k=0;k<j;k++){
            ans[v[k]-1]++;
            // cout<<v[k]<<" ";
        }
        // cout<<endl;
    }
    for(auto i:ans)cout<<i<<" ";
    return 0;
}
/*
bao li!!! 
ccf i love you!!!!

// ccf,i love you:
// i love three things in the world
// the sun,the moon,and ccf;
// i love the sun for days
// the moon for nights
// and ccf forever

zhe shi he wo men yin yu lao shi xue de

hahahahaha
wo yao shang qi pa da shang !!!!!!

     a       k    k  iiiiiii    ooo    iiiiiii
    a a      k   k      i      o   o      i   
   a   a     k k        i     o     o     i   
  a a a a    k k        i     o     o     i  
 a       a   k   k      i      o   o      i
a         a  k    k  iiiiiii    ooo    iiiiiii

*/