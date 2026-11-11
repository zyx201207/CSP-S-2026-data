#include<bits/stdc++.h>
using namespace std;
struct str{
    long long len;
    char tmp;
}a[200005];
long long n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    long long l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].tmp;
        l+=a[i].len;
    }
    long long address=0;
    long long left_address=1,right_address=n;
    long long left_len=a[1].len,right_len=a[n].len;
    while(address<l/2){
        if(left_len==0){
            left_len=a[++left_address].len;
        }
        if(right_len==0){
            right_len=a[--right_address].len;
        }
        int minmin;
        if(left_len<=right_len){
            minmin=a[left_address].len;
        }else{
            minmin=a[right_address].len;
        }
        address+=minmin;
        left_len-=minmin;
        right_len-=minmin;
        if(a[left_address].tmp!=a[right_address].tmp) ans+=minmin;
    }
    cout<<ans;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}