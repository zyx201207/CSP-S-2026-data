#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int an;
vector<int> v1,v2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v1.push_back(a[i]);
    }
    for(int l=30;l>=0;l--){
        int c=0;
        int t=v1.size();
        for(int i=0;i<t;i++){
            int x=v1[i];
            if(x&(1<<l)){
                v2.push_back(x);
                c++;
            }
        }
        if(c>=m){
            an|=1<<l;
            v1=v2;
        }
        v2.clear();
    }
    printf("%d",an);
    return 0;
}
