#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    long long w=0;
    long long cnm=0;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        char q;
        cin>>q;
        for(int j=w;j<w+a;j++){
            s[j]=q;
            cnm=j;
        }
        w=w+a;
    }
    cnm=cnm+1;
    int cnt=0;
    int k=0;
    int l=cnm-1;
    if(cnm%2==0){
        while(k!=l+1){
            if(s[k]!=s[l]){
                cnt++;
            }
            k++;
            l--;
        }
        cout<<cnt;
    }else{
        while(k!=l){
            if(s[k]!=s[l]){
               cnt++;
            }
            k++;
            l--;
        }
        cout<<cnt;
    }

    return 0;
}
