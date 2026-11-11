#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct str{
    long long len;
    char c;
}stri[200005];
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>stri[i].len>>stri[i].c;
    }
    long long need=0;
    long long i=1,j=n;
    while(i<j){
        if(stri[i].c!=stri[j].c){
            if(stri[i].len==stri[j].len){
                    need+=min(stri[i].len,stri[j].len);
                    i++;j--;
            }
            else if(stri[i].len<stri[j].len){
                need+=stri[i].len;
                stri[j].len-=stri[i].len;
                i++;
            }else if(stri[i].len>stri[j].len){
                need+=stri[j].len;
                stri[i].len-=stri[j].len;
                j--;
            }
        }else{
            if(stri[i].len<stri[j].len){
                stri[j].len-=stri[i].len;
                i++;
            }else if(stri[i].len>stri[j].len){
                stri[i].len-=stri[j].len;
                j--;
            }else{
                i++,j--;
            }
        }
    }
    cout<<need;
    return 0;
}
