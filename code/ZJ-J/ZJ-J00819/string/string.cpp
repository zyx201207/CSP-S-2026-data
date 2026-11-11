#include<bits/stdc++.h>
using namespace std;
long long n,ans,tot;
struct period{
    long long l,r;
    char c;
}p[200005];
vector <period> v1,v2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long len,sum=1;
    for(int i=1;i<=n;i++){
        cin>>len>>p[i].c;
        p[i].l=sum;
        p[i].r=sum+len-1;
        sum+=len;
        tot+=len;
    }
//    for(int i=1;i<=n;i++){
//    	cout<<p[i].l<<" "<<p[i].r<<" "<<p[i].c<<"\n";
//	}
    long long w=0;
    sum=0;
    while(sum+p[w+1].r-p[w+1].l+1<=tot/2){
        w++;
        v1.push_back(p[w]);
        sum+=p[w].r-p[w].l+1;
    }
    if(sum<tot/2) v1.push_back({p[w+1].l,tot/2,p[w+1].c});
    w=n+1;
    sum=0;
    while(sum+p[w-1].r-p[w-1].l+1<=tot/2){
        w--;
        v2.push_back({tot-p[w].r+1,tot-p[w].l+1,p[w].c});
        sum+=p[w].r-p[w].l+1;
    }
    if(sum<tot/2) v2.push_back({tot-p[w-1].r+1,tot/2,p[w-1].c});
    long long pos1=0,pos2=0,loc=1;
    while(pos1<v1.size()&&pos2<v2.size()&&loc<=tot/2){
        if(v1[pos1].c!=v2[pos2].c) ans+=min(v1[pos1].r,v2[pos2].r)+1-loc;
        loc=min(v1[pos1].r,v2[pos2].r)+1;
        if(v1[pos1].r<v2[pos2].r) pos1++;
        else if(v1[pos1].r==v2[pos2].r){
            pos1++;
            pos2++;
        }
        else pos2++;
    }
//    for(int i=0;i<v1.size();i++) cout<<v1[i].l<<" "<<v1[i].r<<" "<<v1[i].c<<"\n";
//    cout<<"\n";
//    for(int i=0;i<v2.size();i++) cout<<v2[i].l<<" "<<v2[i].r<<" "<<v2[i].c<<"\n";
    cout<<ans;
    return 0;
}
