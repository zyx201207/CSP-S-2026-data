#include<bits/stdc++.h>
using namespace std;
struct node{
    long long s=0;
    char ch;
}a[200010],b;
long long sum=0;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b.s>>b.ch;
        if(b.ch==a[i-1].ch){
            a[i-1].s=a[i-1].s+b.s;
            i--;
            n--;
            continue;
        }else{
            a[i].s=b.s;
            a[i].ch=b.ch;
        }
    }
    long long l=1,r=n,mid=(r-l)/2+l,long1=0,long2=0;
    if(n==1){
        cout<<0;
        return 0;
    }
    while(l<=mid&&r>=mid){
        if(l==r){
            break;
        }
        if(a[l].ch==a[r].ch){
            if(a[l].s==a[r].s){
                continue;
            }
            long long c=abs(a[l].s-a[r].s);
            sum+=c;
            if(a[l].s>a[r].s){
                while(c){
                    r--;
                    if(c>=a[r].s){
                        c-=a[r].s;
                        if(c==0) r--;
                    }else{
                        a[r].s-=c;
                        break;
                    }
                }
            }else{
                while(c){
                    l++;
                    if(c>=a[l].s){
                        c-=a[l].s;
                        if(c==0) l++;
                    }else{
                        a[l].s-=c;
                        break;
                    }
                }
            }
        }else{
            if(a[l].s<a[r].s){
                sum+=a[l].s;
                a[r].s-=a[l].s;
                l++;
            }else if(a[l].s==a[r].s){
                sum+=a[l].s;
                r--;
                l++;
            }else{
                sum+=a[r].s;
                a[l].s-=a[r].s;
                r--;
            }
        }
    }
    cout<<sum;

    return 0;
}
