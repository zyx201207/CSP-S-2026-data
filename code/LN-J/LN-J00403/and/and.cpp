#include<bits/stdc++.h>

using namespace std;

long long n,m;
long long ans=INT_MAX;
long long wei[30];
struct num{
    string omz;
    long long nu;
}a[200000];


bool cmp(num a,num b){
    return a.nu>b.nu;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i].nu;
        int tem=a[i].nu;
        int c=0;
        while(tem){
            wei[c]=tem%2;
            a[i].omz+=(char)tem%2-'0';
            tem=tem/2;
            c++;
        }
    }
    sort(a,a+n,cmp);
    ans=a[m-1].nu;

 //     for(int i=30;i>0;i++){
   //     if(wei[i]>=m){
     //       for(int j=0;j<n;j++){
       //             int c;
         //       if(a[j].omz[i]){
           //         ans=a[j].nu&ans;
             //       c++;
               // }
 //               if(c==m){
   //                 break;
     //           }
       //     }
  //      }
//    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
