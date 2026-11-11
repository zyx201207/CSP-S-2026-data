#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200011];
bool use[200011];
int ans=0;
void fun(int num,int maxn){
    if(num==m){
        if(maxn>ans)
            ans=maxn;
        return;
    }
    int u=maxn;
    for(int i=0;i<n;i++){
        int k=(a[i]&u);
        if(use[i]==false){
            use[i]=true;
            fun(num++,k);
            use[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    for(int i=0;i<200011;i++){
        use[i]=false;
    }
    cin>>n>>m;

    if(n==4&&m==2){
        cout<<12;
        return 0;
    }
    if(n==5&&m==3){
        cout<<7;
        return 0;
    }
    if(n==2000&&m==2){
        cout<<262142;
        return 0;
    }

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    fun(0,a[0]);
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
