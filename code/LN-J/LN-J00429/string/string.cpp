//#include<bits/stdc++.h>
//using namespace std;
//struct z{
//    long long l;
//    long long r;
//   char c;
//};
//struct f{
//    long long l;
//    long long r;
//    char c;
//};
//z zz[200005];
//f ff[200005];
//long long sum[200005];
//int main(){
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        int len;
//       cin>>len>>zz[i].c;
//        sum[i]=sum[i-1]+len;
//    }
//    for(int i=1;i<=n;i++){
//        zz[i].l=sum[i-1]+1;
//        zz[i].r=sum[i];
//
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
char s[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=cnt+1;j<=cnt+a;j++){
            s[j]=c;
        }
        cnt+=a;
    }
    long long sum=0;
    for(long long i=1;i<=cnt;i++){
        if(s[i]!=s[cnt-i+1]){
            sum++;
        }
    }
    cout<<sum/2;
    return 0;
}
