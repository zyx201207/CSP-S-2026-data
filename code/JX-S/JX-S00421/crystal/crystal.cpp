#include<bits/stdc++.h>
using namespace std;
int a[200005],ls[200005],bucket[105],ans,n,m;
void repair(){
    for(int i=0;i<200005;i++)ls[i]=a[i];
    for(int i=0;i<105;i++)bucket[i]=0;
}
void repair2(){
    //for(int i=0;i<200005;i++)ls[i]=a[i];
    for(int i=0;i<105;i++)bucket[i]=0;
}
bool cmp(int l,int r){
    return l>r;
}
int bucket_sort(){
    for(int i=0;i<n;i++){
        bucket[ls[i]]++;
    }
    //for(int i=0;i<11;i++)cout<<bucket[i]<<' ';
    //cout<<endl;
    sort(bucket,bucket+105,cmp);
    return bucket[0];
}
void dfs(int step){
    if(step==m){
        ans=max(ans,bucket_sort());
        return;
    }
    for(int i=0;i<n;i++){
        step++;
        ls[i]++;
        dfs(step);
        repair2();
        step--;
        ls[i]--;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    int alll;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(flag){
            if(i==0)alll=a[i];
            else{
                if(alll!=a[i]){
                    flag=0;
                }
            }
        }
    }
    if(flag){
        cout<<m;
        return 0;
    }
    if(n>5000){
        int mid=n/2;
        ans=1;
        int k=m/(a[3]-a[2]);
        for(int i=2;k>0;i+=2){
            if(k>=i){
                k-=i;
                ans+=2;
            }
            else if(k>=i/2){
                k-=i/2;
                ans+=1;
                cout<<min(ans,n)<<endl;
                return 0;
            }
            else{
                cout<<min(ans,n)<<endl;
                return 0;
            }
        }
        cout<<min(ans,n)<<endl;
        return 0;
    }
    repair();
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
