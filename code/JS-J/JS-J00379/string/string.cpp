#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
struct Node{
    int len;
    char c;
}a[maxn];
long long n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].len>>a[i].c;
    for(int i=1,j=n;i<=n,j>=1,i<j;){
        if(a[i].len<a[j].len){
            if(a[i].c!=a[j].c) ans+=a[i].len;
            a[j].len-=a[i].len;a[i].len=0;
            i++;
        }else if(a[i].len>a[j].len){
            if(a[i].c!=a[j].c) ans+=a[j].len;
            a[i].len-=a[j].len;a[j].len=0;
            j--;
        }else if(a[i].len==a[j].len){
            if(a[i].c!=a[j].c) ans+=a[i].len;
            a[j].len=0,a[i].len=0;
            i++,j--;
        }
    }
    cout<<ans;
	return 0;
}
/*
I often recall about the past.
*/
