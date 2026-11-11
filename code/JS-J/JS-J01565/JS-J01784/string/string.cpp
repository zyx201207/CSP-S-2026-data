#include<bits/stdc++.h>
using namespace std;
struct node{
    long long be,en;
    char c;
};
node q[200005];
int n;
long long sum=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //check this before you submit!

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        q[i]={q[i-1].en+1,q[i-1].en+a,c};
    }

    long long l=1,r=q[n].en,i=1,ii=n;
    char c1=q[1].c,c2=q[n].c;
    while(i<=n&&ii>=1){
        long long en1,en2;
        if(l>q[i].en){
            c1=q[++i].c;
        }
        en1=q[i].en-l;
        if(r<q[ii].be){
            c2=q[--ii].c;
        }
        en2=r-q[ii].be;
        long long next=min(en1,en2);
        if(c1!=c2){
            sum+=next+1;
        }
        l+=next,r-=next;
        l++;r--;
    }
    cout<<sum/2;
    return 0;
}
