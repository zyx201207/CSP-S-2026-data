#include "bits/stdc++.h"
using namespace std;
const int N=2e5+5;
int n;
long long sum=0,ans;
struct node{
    long long s,e;
    char c;
}a[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k>>a[i].c;
        a[i].s=a[i-1].e+1;
        a[i].e=a[i].s+k-1;
        sum+=k;
    }
    if(sum%2==1){
        for(int i=1,j=n;;){
            int s1=(min(a[i].e,sum/2+1)-a[i].s);
            int s2=(a[j].e-max(a[j].s,sum/2+1));
            if(s1==s2){
                if(a[i].c!=a[j].c)
                    ans+=(s1+1);
                i++,j--;
                  //  cout<<"A "<<ans<<" "<<a[i].e<<" "<<a[j].s<<endl;
            }
            else if(s1<s2){
                if(a[i].c!=a[j].c)
                    ans+=(s1+1);
                i++;
                a[j].e-=(s1+1);
              //  cout<<"B "<<ans<<" "<<a[i].e<<" "<<a[j].s<<" "<<a[j].e<<endl;

            }
            else if(s1>s2){
                if(a[i].c!=a[j].c)
                    ans+=(s2+1);
                j--;
                a[i].s+=(s2+1);
               // cout<<"C "<<ans<<" "<<a[i].e<<" "<<a[j].s<<" "<<a[i].s<<endl;

            }
            if( (a[i].s>=(sum/2+1)) || (a[j].e<=(sum/2+1)) )
                break;
        }
    }
    else{
        for(int i=1,j=n;;){
            int s1=(min(a[i].e,sum/2+1)-a[i].s);
            int s2=(a[j].e-max(a[j].s,sum/2+1));
            if(s1==s2){
                if(a[i].c!=a[j].c)
                    ans+=(s1+1);
                i++,j--;
                  //  cout<<"A "<<ans<<" "<<a[i].e<<" "<<a[j].s<<endl;
            }
            else if(s1<s2){
                if(a[i].c!=a[j].c)
                    ans+=(s1+1);
                i++;
                a[j].e-=(s1+1);
              //  cout<<"B "<<ans<<" "<<a[i].e<<" "<<a[j].s<<" "<<a[j].e<<endl;

            }
            else if(s1>s2){
                if(a[i].c!=a[j].c)
                    ans+=(s2+1);
                j--;
                a[i].s+=(s2+1);
               // cout<<"C "<<ans<<" "<<a[i].e<<" "<<a[j].s<<" "<<a[i].s<<endl;

            }
            if( (a[i].s>(sum/2+1)) || (a[j].e<(sum/2+1)) )
                break;
        }
    }
    cout<<ans;
    return 0;
}
