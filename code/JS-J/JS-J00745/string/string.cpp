#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,p=0,q=0;
struct st{
    long long cnt;
    char a;
}s[201000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    st s2[201000];
    for(int i=0;i<n;i++){
        cin>>s[i].cnt>>s[i].a;
        s2[n-i-1].cnt=s[i].cnt;
        s2[n-i-1].a=s[i].a;
    }while(p<n-1||q<n-1){
        if(s[p].a!=s2[q].a){
            if(s[p].cnt>s2[q].cnt){
                    s[p].cnt-=s2[q].cnt;
                    sum+=s2[q].cnt;
                    q++;
                    continue;
            }if(s[p].cnt==s2[q].cnt){
                    sum+=s2[q].cnt;
                    q++;
                    p++;
                    continue;
            }if(s[p].cnt<s2[q].cnt){
                    s2[q].cnt-=s[p].cnt;
                    sum+=s[p].cnt;
                    p++;
                    continue;
            }
        }else{
            if(s[p].cnt>s2[q].cnt){
                    s[p].cnt-=s2[q].cnt;
                    q++;
                    continue;
            }if(s[p].cnt==s2[q].cnt){
                    q++;
                    p++;
                    continue;
            }if(s[p].cnt<s2[q].cnt){
                    s2[q].cnt-=s[p].cnt;
                    p++;
                    continue;
            }
        }
    }sum+=s[n-1].cnt;
    cout<<sum/2;
    return 0;
}
