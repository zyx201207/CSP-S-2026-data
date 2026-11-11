#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
priority_queue<int> q;
int n,M;
int a[N],b[N];
map<int,int> m;
map<int,int> mm;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>M;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=n;i>=1;i--){
        if(m[a[i]]==1) {
            break;
        }
        m[a[i]]++;
        cnt++;
    }
    int s=cnt;
    for(int i=n;i>=n-cnt;i--){
        mm[a[i]]+=s;
        s--;
    }
    for(int i=1;i<=M;i++) m[i]=0;
    for(int i=1;i<=n-cnt;i++){
        for(int j=i;j<=n;j++){
            if(m[a[j]]==1){
                for(int z=b[a[j]];z<=j;z++) m[a[z]]=0;
            }
            b[a[j]]=j;
            m[a[j]]++;
        }
        for(int j=1;j<=M;j++){
            mm[j]+=m[j];
            m[j]=0;
        }
    }
    for(int i=1;i<=M;i++) cout<<mm[i]<<" ";
    return 0;
}
//4 3
//1 2 1 3
//10 3
 //3 1 2 1 3 2 3 1 2 1

