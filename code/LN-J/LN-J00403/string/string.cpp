#include<bits/stdc++.h>

using namespace std;

int n=0;
int a=0;
char c=' ';
string str="";
long long ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            str+=c;
        }
    }

    for(int i=0;i<=str.size()/2;i++){
        if(str[i]!=str[str.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
