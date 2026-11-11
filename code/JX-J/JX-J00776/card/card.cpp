#include<bits/stdc++.h>
using namespace std;

vector <long long> desk,cnt;
long long a[3000005];
long long m,n,t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    int x=n;
    long long p=0;
    while(n--){
        for(int i=n-x;i<x;i++){
            if(t[a[i]]==0){
                    t[a[i]]++;
                    desk.push_back(a[i]);
            }
            else {
                t[a[i]]=0;
                int j=i;
                while(desk[j]!=a[i]){
                    desk[j]=0;
                    j--;
                }
            }
        }
        for(int i=0;i<m;i++){
            cnt.push_back(desk[i]);
        }
    }
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=1;j<=cnt.size();j++){
            if(cnt[i]==i)num++;
        }
        cout<<num<<' ';
    }
    return 0;
}
