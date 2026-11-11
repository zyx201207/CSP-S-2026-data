#include <bits/stdc++.h>
using namespace std;


vector<long long> linen;
vector<char> lines;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long beg=0;
    long long sigma=0;
    long long ans=0;
    int n;
    cin>>n;
    lines.resize(2*n+1);
    linen.resize(2*n+1);
    linen[0]=-1;
    lines[0]='A';
    for(int i=1;i<=n;i++){
        long long len;
        char ins;
        cin>>len>>ins;
        lines[2*i-1]=ins;
        linen[2*i-1]=beg+1;
        lines[2*i]=ins;
        linen[2*i]=beg+len;
        beg=beg+len;
        sigma+=len;
        //cout<<beg<<endl;
    }
    for(int i=1;i<)

    for(int i=1;i<=sigma/2;i++){
        long long q=sigma-i+1;
        auto l=lower_bound(linen.begin(),linen.end(),i);
        auto r=lower_bound(linen.begin(),linen.end(),q);

        if(lines[l-linen.begin()] != lines[r-linen.begin()]){
            //cout<<"when compare "<<i<<"and"<<q;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}


