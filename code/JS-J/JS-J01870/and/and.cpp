#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
string b[200100];
vector<int> rec[32];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int t=x;
        int wei=1;
        while(x>0){
            if(x%2==1){
                rec[wei].push_back(t);
            }
            x/=2;
            wei++;
        }
    }
    for(int i=31;i>=0;i--){
        int maxrec=0;
        int k=rec[i].size();
        if(rec[i].size()>=m){
            int d[k];
            for(int j=0;j<rec[i].size();j++){
                    d[j]=rec[i][j];}

            sort(d,d+k);
            int ans=d[k-1];
            for(int j=k-1;j>k-1-m;j--){
                ans=ans&d[j];
            }
            cout<<ans;
            return 0;
        }
    }
    cout<<0;
}



