#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,pre;
int a[400000];
char c[400000];
/*
2
2 a
3 a
*/
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
    }
//    if(cnt%2!=0)cnt--;
    int l=1,r=n,lal=0,lar=n+1;
    while(l<r){
        int l_be=lal+1,l_en=l_be+a[l]-1;
        int r_be=lar-1,r_en=r_be-a[r]+1;
        if(c[l]!=c[r]){
            if(n-l_en+1==r_en){
                lal=l_en;
                lar=r_en;
                l++;
                r--;
            }else if(n-l_en+1<r_en){
                lar=r_en;
                r--;
            }else{
                lal=l_en;
                l++;
            }
        }else{//xiangtong
            int ren=n-r_en+1,rbe=n-r_be+1;
 //           cout<<rbe<<" "<<ren<<endl;
 //           cout<<l_be<<" "<<l_en<<endl;
            int minn=max(rbe,l_be),maxx=min(ren,l_en);
            pre+=2*(maxx-minn+1);
            if(l_en==ren){
                lal=l_en;
                lar=r_en;
                l++;
                r--;
            }else if(l_en>ren){
//                cout<<1<<endl;
                lar=r_en;
                r--;
            }else{
                lal=l_en;
                l++;
            }
        }
    }
/*
 6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
 */
    if(l==r){
  //          cout<<pre<<endl;//<<" "<<l<<" "<<a[l]<<endl;
        int be=lal+1,en=be+a[l]-1;
        int mid=cnt/2+1;
  //          cout<<be<<" "<<mid<<"  "<<en<<endl;
        int x=min((mid-be),(en-mid));
  //          cout<<x<<endl;
        x*=2;
        x++;
        pre+=x;
    }
    cout<<(cnt-pre)/2;
    return 0;
}
