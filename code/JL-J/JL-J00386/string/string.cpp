#include<bits/stdc++.h>
using namespace std;
int a[200002];
char c[200002];
string s;
int sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int b=s.size();
    for(int i=0;i<b/2;i++){
        for(int j=0;j>b/2;j--){
            if(i!=j){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
