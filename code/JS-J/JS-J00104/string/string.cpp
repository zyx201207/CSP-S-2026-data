#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,char> s[200010];
int l,r;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        s[i].first=a;
        s[i].second=c;
    }
    l=1,r=n;
    while(l<r){
        if(s[l].second==s[r].second){
            int l_before_num=s[l].first;
            int r_before_num=s[r].first;
            int l_before=l;
            int r_before=r;
            if(l_before_num>=r_before_num){
                s[l_before].first-=r_before_num;
                r--;
            }
            if(l_before_num<=r_before_num){
                s[r_before].first-=l_before_num;
                l++;
            }
        }
        else{
            int l_before_num=s[l].first;
            int r_before_num=s[r].first;
            int l_before=l;
            int r_before=r;
            if(l_before_num>r_before_num){
                s[l_before].first-=r_before_num;
                ans+=r_before_num;
                r--;
            }
            else if(l_before_num<r_before_num){
                s[r].first-=l_before_num;
                ans+=l_before_num;
                l++;
            }
            else if(l_before_num==r_before_num){
                ans+=l_before_num;
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
