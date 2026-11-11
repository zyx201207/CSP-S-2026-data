#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<char> c;
long long n,x,id=0,ans,len,olen;
char y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(id==0||y!=c[id-1]){
            a.push_back(x);
            c.push_back(y);
            id++;
        }
        else{
            a[id-1]+=x;
        }

    }
    len=a.size();
    olen=len;
    int i=0;
    while(i<len/2){
        if(c[i]==c[len-i-1]){
            if(a[i]>=a[len-i-1]){
                bool cflag=false;
                if(a[i]==a[len-i-1]){
                    cflag=true;
                }
                a[i]-=a[len-i-1];
                a[len-i-1]=0;
                len--;
                if(cflag==true){
                    len++;
                    i++;
                }
            }
            else{
                a[len-i-1]-=a[i];
                a[i]=0;
                len++;
                i++;
            }
        }
        else{
            if(a[i]>=a[len-i-1]){
                bool dflag=false;
                if(a[i]==a[len-i-1]){
                    dflag=true;
                }
                ans+=a[len-i-1];
                a[i]-=a[len-i-1];
                a[len-i-1]=0;
                len--;
                if(dflag==true){
                    len++;
                    i++;
                }
            }
            else{
                ans+=a[i];
                a[len-i-1]-=a[i];
                a[i]=0;
                len++;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
