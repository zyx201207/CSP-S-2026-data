#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define M 300005
using namespace std;

int n,m;
int a[N],ans[M];
vector<int> v;
bool flag;

int check(vector<int> v,int x){
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i-1]>a[i]&&i!=1){
            flag=true;
        }
    }
    for(int k=1;k<=n;k++){
        v.clear();
        for(int i=k;i<=n;i++){
            int res=check(v,a[i]);
            if(res!=-1){
                if(!flag){
                    v[res]=0;
                }
                else{
                    for(int i=res;i<v.size();i++){
                        v[i]=0;
                    }
                }
                v.push_back(a[i]);
            }
            else v.push_back(a[i]);
        }
        for(int i:v){
            ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
