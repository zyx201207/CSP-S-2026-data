//#include<bits/stdc++.h>//baoli
//using namespace std;
//const int N=2e5+10;
//typedef long long ll;
//ll n;
//struct node{
//    int aa;
//    string cc;
//}a[N];
//ll pos=0;
//string s="";
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        cin>>a[i].aa>>a[i].cc;
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=a[i].aa;j++){
//            s+=a[i].cc;
//        }
//    }
//    for(int i=0;i<s.size();i++){
//        if(s[i]!=s[s.size()-n-1]){
//            pos++;
//        }
//    }
//    cout<<pos<<endl;
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
struct node{
    ll aa;
    string cc;
}a[N];
ll n;
ll pos=0;
ll bj;
ll cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].aa>>a[i].cc;
        cnt+=a[i].aa;
    }
    for(int i=1;i<=n/2;i++){
        if(a[i].cc!=a[n-i+1].cc){
            if(a[i].aa==a[n-i+1].aa){
                pos+=a[i].aa;
            }else{
                pos+=abs(a[i].aa-a[n-i+1].aa);
                bj=max(a[i].aa,a[n-i+1].aa)-min(a[i].aa,a[n-i+1].aa);
                if(a[i].aa>a[n-i+1].aa){
                    a[n-i].aa-=bj;
                    if(a[n-i].cc!=a[i].cc){
                        pos+=bj;
                    }
                }else{
                    a[i+1].aa-=bj;
                    if(a[n-i+1].cc!=a[i+1].cc){
                        pos+=bj;
                    }
                }
            }
            if(a[n/2].cc!=a[n/2+1].cc&&bj!=0){
                pos+=abs(bj-a[(n+1)/2].aa);
            }
        }
    }
    cout<<pos<<endl;
    return 0;
}
