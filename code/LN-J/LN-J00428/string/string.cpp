#include <bits/stdc++.h>
using namespace std;
struct str{
    long long l,r,k;
    char c;
}a[214514];
struct qu{
    long long k;
    char c;
}s1[214514],s2[214514];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c1=1,c2=1;
    cin >> n;
    long long p=1,sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        cin >> a[i].k >> a[i].c;
        a[i].l=p;
        a[i].r=p+a[i].k-1;
        p+=a[i].k;
        sum+=a[i].k;
    }
    long long mid=sum/2+sum%2;
    for(int i=1;i<=n;i++){
        if(a[i].r<=mid){
            s1[c1].c=a[i].c;
            s1[c1].k=a[i].k;
            c1++;
        }else{
            if(a[i].l<mid){
                s1[c1].c=a[i].c;
                s1[c1].k=mid-a[i].l+1;
                c1++;
                s2[c2].c=a[i].c;
                s2[c2].k=a[i].r-mid;
                c2++;
            }else{
                s2[c2].c=a[i].c;
                s2[c2].k=a[i].k;
                c2++;
            }
        }
    }
    for(int i=1;i<=(c2-1)/2;i++){
        swap(s2[i],s2[c2-i]);
    }
    for(int i=1,j=1;i<c1&&j<c2;){
        if(s1[i].k>=s2[j].k){
            cnt+=s2[j].k*(s1[i].c!=s2[j].c);
            s1[i].k-=s2[j].k;
            if(!s1[i].k)i++;
            j++;
        }else{
            cnt+=s1[i].k*(s1[i].c!=s2[j].c);
            s2[j].k-=s1[i].k;
            if(!s2[j].k)j++;
            i++;
        }
    }
    cout << cnt;
    return 0;
}
