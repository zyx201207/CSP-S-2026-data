#include<bits/stdc++.h>
using namespace std;

int n;
int a[10000007];
string c[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==1){
        cout<<"0";
        return 0;
    }


    if(n=2){

        for(int i=0;i<n;i++){
            if(c[i]==c[i+1]){
                cout<<"0";
                return 0;
            }
            else if((a[i]+a[i+1])%2==1){
                int Min=min(a[i],a[i+1]);
                cout<<Min;
                break;
            }else{
                if(a[i]==2 && a[i+1]==2){
                    cout<<"2";
                    break;
                }
            }
        }
    }
    return 0;
}
