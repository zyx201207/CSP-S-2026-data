#include<bits/stdc++.h>
using namespace std;
int ans=0;
int f1(int a,int b){
    int p=pow(2,b);
    a=a/(p/2);
    if(a%2==1){
        return 1;
    }else{
        return 0;
    }
}
void f(vector<int> v,int m){
    int la[100]{};
    int l=v.size()-1,maxn=0,k=0x3f3f3f3f;
    for(int i=0;i<=l;i++){
        int num=v[i],j=0;
        while(num>0){
            if(num%2==1){
                la[j]++;
            }
            num/=2;
            maxn=max(maxn,j);
            j++;

        }
    }
    for(int i=maxn;i>=0;i--){
        if(la[i]>=m){
            k=i;
            break;
        }
    }
    if(k==0x3f3f3f3f){
        cout<<ans;
        return;
    }else if(k==0){
        cout<<ans+1;
        return;
    }else{
        ans+=pow(2,k);
        vector<int> v1;
        for(int i=0;i<=l;i++){
            if(f1(v[i],k)){
                 v1.push_back(v[i]-pow(2,k));
            }
        }
        f(v1,m);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    f(v,m);
    return 0;
}

