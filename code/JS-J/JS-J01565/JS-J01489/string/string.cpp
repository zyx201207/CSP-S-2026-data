#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,sum;
struct node{
    char c;
    int l;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        ans+=a[i].l;
    }
    long long i=1,j=ans;
    char s=a[1].c,f=a[n].c;
    int l=1,r=n;
    while(i<j){
        if(s==f){
            if(a[l].l<a[r].l){
                i+=a[l].l;
                j-=a[l].l;
                a[r].l-=a[l].l;
                l++;
                s=a[l].c;
            }else if(a[l].l>a[r].l){
                i+=a[r].l;
                j-=a[r].l;
                a[l].l-=a[r].l;
                r--;
                f=a[r].c;
            }else{
                i+=a[l].l;
                j-=a[l].l;
                l++;
                r--;
                s=a[l].c;
                f=a[r].c;
            }
        }else{
            sum+=min(a[l].l,a[r].l);
            if(a[l].l<a[r].l){
                i+=a[l].l;
                j-=a[l].l;
                a[r].l-=a[l].l;
                l++;
                s=a[l].c;
            }else if(a[l].l>a[r].l){
                i+=a[r].l;
                j-=a[r].l;
                a[l].l-=a[r].l;
                r--;
                f=a[r].c;
            }else{
                i+=a[l].l;
                j-=a[l].l;
                l++;
                r--;
                s=a[l].c;
                f=a[r].c;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
