#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    string al="";
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        al+=a[i]+'0';
    }
    int sum[m+1];
    for(int i=0;i<=m;i++){
        sum[i]=0;
    }
    for(int i=0;i<n;i++){
        string bl="";
        for(int j=i;j<n;j++){
            bl+=al[j];
        }
        for(int j=0;j<bl.length();j++){
            for(int e=0;e<j;e++){
                if(bl[e]==bl[j]){
                    bl.erase(e,j-e);
                    j=0;
                }
            }
        }
        for(int w=0;w<bl.length();w++){
            sum[bl[w]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
