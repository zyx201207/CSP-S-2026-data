#include<bits/stdc++.h>
using namespace std;
string s[200005];
long long t[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string x;
    long long a,sum=0,b;
    cin>>a;
    for(long long i=1;i<=a;i++)
    {
        cin>>b>>x;
        s[i]+=x;
        t[i]+=b;
    }
    long long l=1,r=a,ll=t[1],rr=t[a];
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            sum+=min(ll,rr);
            if(ll>rr){
                ll=ll-rr;
                r--;
                rr=t[r];
            }
            else if(ll==rr)
            {
                l++;
                r--;
                ll=t[l];
                rr=t[r];
            }
            else{
                rr=rr-ll;
                l++;
                ll=t[l];
            }
        }
        else{
            int g=min(ll,rr);
            ll-=g;
            rr-=g;
            if(ll==0){
                l++;
                ll=t[l];
            }
            if(rr==0){
                r--;
                rr=t[r];
            }
        }
    }
    cout<<sum;
    return 0;
}
