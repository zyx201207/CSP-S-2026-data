#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string v;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        while(a--){
            v.pushback(c);
        }
    }
    int x=v.size();
    string t;
    string s;
    if(x%2==1){
        for(int i=0;i<n/2;i++){
            t+=v[i];
        }
        for(int i=q+1;i<n;i++){
            s=v[i];
        }
        for(int i=0;i<n/2;i++){


            if(t[i]!=s[i]){
                int sum++;
            }
        }
    }else{
        for(int i=0;i<n/2;i++){
            t+=v[i];
        }
        for(int i=q;i<n;i++){
            s=v[i];
        }
        for(int i=0;i<n/2;i++){

            if(t[i]!=s[i]){
                int sum++;
            }
        }
    }
    cout<<sum;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
