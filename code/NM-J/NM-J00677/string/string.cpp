#include<bits/stdc++.h>
using namespace std;
int n,a,ans1;
char b;
string s;
int hw(string s){
    int ans2=0;
    int l,r;
    if(s.size()%2!=0){
        l=s.size()/2+1,r=s.size()/2+1;
    }
    else {
        l=s.size()/2,r=s.size()/2+1;
    }
    while(l>=0&&r<=s.size()-1){
        if(s[l]!=s[r]){
            ans2++;
            s[l]=s[r];
        }
        l--;
        r++;
    }
    if(ans2%2!=0)return ans2/2+1;
    else return ans2/2;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>b;
        ans1+=a;
        for(int i=0;i<=ans1-1;i++){
            s=s+b;
        }
    }
    cout<<hw(s);
}
