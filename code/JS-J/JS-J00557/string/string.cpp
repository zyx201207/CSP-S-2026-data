#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+10;
int n;
int a[N];
char c[N];
int sum_len;
int idl,idr,lenl,lenr;
char cl,cr;
int ans;
vector<char> v;

void init();

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
//            cout<<sum_len+j<<" "<<s[sum_len+j]<<endl;
            v.push_back(c[i]);
        }
        sum_len+=a[i];
    }

    int l=0,r=v.size()-1;

    while(l<=r){
        if(v[l]!=v[r]){
            ans++;
        }
        l++,r--;
    }


//    init();
//    while(idl>=1||idr<=n){
//        if(cl!=cr){
//            ans+=llabs(lenl-lenr);
//        }
//        if(lenl>lenr&&idl>=1){
//            lenl-=a[idl];
//            cl=c[idl];
//            idl--;
//        }else{
//            if(idr<=n){
//                lenr-=a[idr];
//                cr=c[idr];
//                idr++;
//            }
//
//        }
//    }
    cout<<ans;
    return 0;
}

//void init(){
//    if(sum_len%2==1){
//        int mid=(sum_len+1)/2;
//        int midsum=0;
//        for(int i=1;i<=n;i++){
//            midsum+=a[i];
//            if(midsum>=mid){
//                idl=i-1;
//                lenl=midsum-a[i];
//                idr=i+1;
//                lenr=sum_len-midsum;
//                cl=c[max(1LL,i-1)];
//                cr=c[min(n,i+1)];
//
//                break;
//            }
//        }
//    }else{
//        int mid=(sum_len)/2;
//        int midsum=0;
//        for(int i=1;i<=n;i++){
//            midsum+=a[i];
//            if(midsum==mid){
//                idl=i;
//                lenl=lenr=sum_len/2;
//                idr=i+1;
//                cl=c[i];
//                cr=c[i+1];
//                break;
//            }
//            if(midsum>mid){
//                idl=i-1;
//                lenl=midsum-a[i];
//                idr=i+1;
//                lenr=sum_len-midsum;
//                cl=c[max(1LL,i-1)];
//                cr=c[min(n,i+1)];
//            }
//        }
//    }
//}

