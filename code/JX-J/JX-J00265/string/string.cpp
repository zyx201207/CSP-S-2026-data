#include<bits/stdc++.h>
using namespace std;
struct st{
    long long m;
    char c;
};
st a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x=1;
    long long m1;
    char c1;
    cin >> n;
    int nn = n;
    while(nn>0){
        cin >> m1 >> c1;
        if(a[x].c!=c1){
            a[x+1].c=c1;
            a[x+1].m+=m1;
        }
        else{
            a[x].c=c1;
            a[x].m+=m1;
        }
        x++;
        nn--;
    }
    if(x==1){
        cout << 0;
        return 0;
    }
    int r = n,l = 1,s=0;
    while(l<=r){
        if(a[l].m==0){
            l++;
        }
        if(a[r].m==0){
            r--;
        }
        if(a[l].m==a[r].m&&a[l].c==a[r].c){
            continue;
        }
        else if(a[l].m!=a[r].m&&a[l].c==a[r].c){
            if(a[r].m>a[l].m){
                a[l+1].m-=a[r].m-a[l].m;
                a[l].m=a[r].m;
                s+=a[r].m-a[l].m;
            }
            else{
                a[r-1].m-=a[l].m-a[r].m;
                a[r].m=a[l].m;
                s+=a[l].m-a[r].m;
            }
        }
        else if(a[l].m==a[r].m&&a[l].c!=a[r].c){
            a[l].c=a[r].c;
            s+=a[l].m;
        }
        else{
            if(a[r].m>a[l].m){
                a[l].c=a[r].c;
                s+=a[l].m;
                a[l+1].m-=a[r].m-a[l].m;
                a[l].m+=a[r].m-a[l].m;
                s+=a[r].m-a[l].m;
            }
            else{
                a[r].c=a[l].c;
                s+=a[r].m;
                a[r-1].m-=a[l].m-a[r].m;
                a[r].m+=a[l].m-a[r].m;
                s+=a[r].m-a[l].m;
            }
        }
        l++;
        r--;
    }
    cout << s;
    return 0;
}
