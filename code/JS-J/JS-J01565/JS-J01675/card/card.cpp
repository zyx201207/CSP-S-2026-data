#include <bits/stdc++.h>
using namespace std;
int a[500005];
vector<int>b;
bool f[300005];
int cnt[300005];
int app(int head,int j){
    for(int i=head;i<j;i++){
        if(b[i]==b[j]){
            return i;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int head=0;
    for(int i=1;i<=n;i++){
        b.clear();
        for(int j=i;j<=n;j++){
            b.push_back(a[j]);
            int k=app(head,j-i);
            if(k!=-1){
                for(int r=k+1;r<=j;r++){
                    f[b[r]]=false;
                }
                head=j-i+1;
            }
            f[a[j]]=true;
        }
        for(int j=1;j<=m;j++){
            if(f[j]){
                cnt[j]++;
            }
            f[j]=false;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",cnt[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
