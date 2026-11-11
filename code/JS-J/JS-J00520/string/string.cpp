#include<bits/stdc++.h>
using namespace std;
struct cc{
    int x;
    char c;
};
int n,k,l;
long long s,ans,ss;
cc a[200010],b[100010],c[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        s+=a[i].x;
        if(a[i].c==a[i-1].c){
            a[i].x+=a[i-1].x;
            a[i-1].x=-1;
        }
    }
    int f=0;
    for(int i=1;i<=n;i++){
        if(a[i].x!=-1){
            ss+=a[i].x;
            if(ss<=s/2){
                b[++k].x=a[i].x;
                b[k].c=a[i].c;
            }
            else{
                if(s%2==1&&f==0){
                        a[i].x--;
                        f=1;
                }
                if(ss-a[i].x<s/2){
                    b[++k].x=s/2-ss+a[i].x;
                    b[k].c=a[i].c;
                    c[++l].x=ss-s/2;
                    c[l].c=a[i].c;
                }
                else{
                c[++l].x=a[i].x;
                c[l].c=a[i].c;
                }
            }
        }
    }
    int ll=l;
    for(int i=1;i<=k;i++){
            while(b[i].x>0){
                if(b[i].c==c[ll].c){
                    if(b[i].x<=c[ll].x){
                        c[ll].x-=b[i].x;
                        b[i].x=0;
                    }
                    else{
                        b[i].x-=c[ll].x;
                        ll--;
                    }
                }
                else{
                    if(b[i].x<=c[ll].x){
                        ans+=b[i].x;
                        c[ll].x-=b[i].x;
                        b[i].x=0;
                    }
                    else{
                        ans+=c[ll].x;
                        b[i].x-=c[ll].x;
                        ll--;
                    }
                }
            }
    }
    cout<<ans;
    return 0;
}
