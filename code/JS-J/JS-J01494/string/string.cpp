#include<iostream>
using namespace std;
long long n,a,cnt;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        s.append(a,c);
    }
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;r--;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
