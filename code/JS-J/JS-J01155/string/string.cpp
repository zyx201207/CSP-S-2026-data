#include<bits/stdc++.h>
using namespace std;
string s1;
int n,sum;
int main(){
    ios::cync_with_stdio(false);
    cin>>tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        while(a--){
            s1+=c;
        }
    }
    for(int i=s1.size()-1,j=0;i>=j;i--,j++){
        if(s1[i]!=s1[j]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
