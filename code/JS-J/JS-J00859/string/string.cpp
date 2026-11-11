#include<bits/stdc++.h>
using namespace std;
struct k{
    long long F;
    char S;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long l;
    char c;
    vector<k>a,b,na,nb;
    for(int i=0;i<n;i++){
        cin>>l>>c;
        k ss;
        ss.F=l;ss.S=c;
        if(i<n/2-1)a.push_back(ss);
        if(i>n/2-1)b.push_back(ss);
    }
    l=0;
    c='A';
    for(int i=0;i<a.size();i++){
        if(c=='A')c=a[i].S;
        else if(a[i].S==c)l+=a[i].F;
        else {
            k ss;
            ss.F=l;ss.S=c;
            na.push_back(ss);
            l=0;
            c='A';
        }
    }
    l=0;
    c='A';
    for(int i=0;i<b.size();i++){
        if(c=='A')c=a[i].S;
        else if(b[i].S==c)l+=b[i].F;
        else {
            k ss;
            ss.F=l;ss.S=c;
            nb.push_back(ss);
            l=0;
            c='A';
        }
    }
    reverse(nb.begin(),nb.end());
    long long x=0;
    int size=max(na.size(),nb.size());
    for(int i=0;i<size;i++){
        long long t=abs(na[i].F-nb[i].F);
        if(na[i].S!=nb[i].S){
            x+=min(na[i].F,nb[i].F);
            if(i<size-1){
                if(na[i].F>=nb[i].F)nb[i].S=na[i].S;
                else na[i].S=nb[i].S;
            }
        }
        else{
            x+=t;
            if(i<size-1){
                if(na[i].F>nb[i].F)na[i+1].F+=t;
                if(nb[i].F>na[i].F)nb[i+1].F+=t;
            }

        }
    }
    cout<<x<<endl;
    return 0;
}