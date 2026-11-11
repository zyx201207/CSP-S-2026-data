#include<bits/stdc++.h>
using namespace std;
vector <char> v;
vector <long long> num;
long long a,ans,n;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    v.push_back('0');
    num.push_back(-1);
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        if(c==v[i-1]){
            num[i]+=a;
        }
        else{
            v.push_back(c);
            num.push_back(a);
        }
    }
    int l=1,r=v.size()-1;
    while(l<r){
        if(v[l]!=v[r]){
        if(num[l]>num[r]){
            ans+=num[r];
            num[l]-=num[r];
            num[r]=0;
            v[r]='0';
            r--;
        }
        else if(num[l]<num[r]){
            ans+=num[l];
            num[r]-=num[l];
            num[l]=0;
            v[l]='0';
            l++;
        }
        }
        else{
            if(num[l]>num[r]){
            num[l]-=num[r];
            r--;
            }
        else if(num[l]<num[r]){
            num[r]-=num[l];
            l++;
            }
        }
    }
    cout<<ans;
    return 0;
    }


