#include<bits/stdc++.h>
using namespace std;
int n,m,fd;
int a[500005];
int s[300005];
vector<int> v;
bool check(int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            fd=i;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int k=1;k<=n;k++){
        v.clear();
        for(int i=k;i<=n;i++){
            if(check(a[i])){
                v.erase(v.begin()+fd,v.end());
            }else{
                v.push_back(a[i]);
            }
        }
        for(int i=1;i<=m;i++){
            if(check(i)){
                s[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",s[i]);
    }
    return 0;
}
