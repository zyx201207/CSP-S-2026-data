#include<bits/stdc++.h>
using namespace std;
int n,m,s=-1;
vector<int> a,b,c;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a.push_back(x);
        if(s==-1) s=x;
        else s=s&x;
        for(int j=i-2;j>=0;j--){
            b.push_back(x&a[j]);
        }
    }
    if(m==1){
        sort(a.begin(),a.end());
        cout<<a.back();
    }
    else if(m==n){
        cout<<s;
    }
    else if(m==2){
        sort(b.begin(),b.end());
        cout<<b.back();
    }
    else if(m==n-1){
            int y=-1;
        for(int i=0;i<n;i++){
            int x=-1;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(x==-1) x=a[j];
                else x&=a[j];
            }
            y=max(x,y);
        }
        cout<<y;
    }
    else{
        sort(a.begin(),a.end());
        cout<<a.back();
    }
    return 0;
}
