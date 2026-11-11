#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
struct node{
    long long num;
    char name;
}s[200009];
void len(int l,int r){
    if(l==r||l>r){
            return;
        }
    if(s[l].num==s[r].num){
        if(s[l].name==s[r].name){
            len(l+1,r-1);
            return;
        }
        else{
            ans+=s[l].num;
            len(l+1,r-1);
            return;
        }
    }
    else if(s[l].name==s[r].name){
            if(s[l].num<s[r].num){
                s[r].num-=s[l].num;
                len(l+1,r);
            }
            else {
                s[l].num-=s[r].num;
                len(l,r-1);
            }
    }
    else{
        if(s[l].num<s[r].num){
                ans+=s[l].num;
                s[r].num-=s[l].num;
                len(l+1,r);
            }
            else {
                ans+=s[r].num;
                s[l].num-=s[r].num;
                len(l,r-1);
            }
    }
}
    int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].num>>s[i].name;
    }
    len(1,n);
    cout<<ans<<endl;
    return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);                                                                                                                               reopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s={};
    for(int i=1;i<=n;i++){
        long long v;
        char c;
        cin>>v>>c;
        for(int j=1;j<=v;j++){
            s+=c;
        }
    }
    long long len=s.size();
    for(long long i=0,j=len-1;i!=j;i++,j--){
        if(s[i]!=s[j])
            ans++;
    }
    cout<<ans;
}
*/
