#include <bits/stdc++.h>
using namespace std;
int a[200000+10],b[200000+10];
vector<int> c[200000+10];
int n,m,sum1=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n-1);
    int j=0;
    for(int i=n-1;i>n-1-m;i--){
        b[j]==a[i];
        j++;
    }
    int y=0;
    while(b[0]!=0){
        c[0][y]=b[0]%2;
        y++;
        b[0]/=2;
    }
    for(int i=1;i<m;i++){
        int k=0;
        while(b[i]!=0){
            c[i][k]=b[i]%2;
            k++;
            b[i]/=2;
        }
        for(int p=0;p<c[i].size();p++){
            c[i][p]=c[i-1][p]&c[i][p];
        }
    }
    for(int i=0;i<c[m-1].size();i++){
        int sum=1;
        if(i!=0){
            for(int w=1;w<=i;w++){
                sum=sum*2;
            }
        }
        
        sum1+=c[m-1][i]*sum;
    }
    cout<<sum1;
    return 0;
}