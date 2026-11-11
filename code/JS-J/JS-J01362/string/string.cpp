#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long a;
    char c;
}b[200001],xb[200001],yb[200001];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sumd=0;
    for(int i=1;i<=n;i++){
        cin>>b[i].a>>b[i].c;
        sumd+=b[i].a;
    }
    int pos;
    long long nx=sumd/2;
    long long ny=sumd/2;
    for(int i=1;i<=n;i++){
        if(nx==0) break;
        if(nx<=b[i].a){
            xb[i].a=nx;
            b[i].a-=nx;
            xb[i].c=b[i].c;
            pos=i;
            break;
        }
        else{
            xb[i].a=b[i].a;
            xb[i].c=b[i].c;
            nx-=b[i].a;
        }
    }
    for(int i=n;i>=pos;i--){
        if(ny==0) break;
        if(ny<=b[i].a){
            yb[i].a=ny;
            b[i].a-=ny;
            yb[i].c=b[i].c;
            pos=i;
            break;
        }
        else{
            yb[i].a=b[i].a;
            yb[i].c=b[i].c;
            ny-=b[i].a;
        }
    }
  //  for(int i=1;i<=1;i++){
 //       cout<<xb[i].a<<" "<<xb[i].c<<" ";
  //  }
  //  cout<<endl;
 //   for(int i=pos;i<=n;i++){
 //       cout<<yb[i].a<<" "<<yb[i].c<<" ";
 //   }
    long long start=1,eend=n,cnt=0;
    while(start!=pos+1&&eend!=pos-1){
        if(xb[start].a>yb[eend].a){
            xb[start].a-=yb[eend].a;
            if(xb[start].c!=yb[eend].c){
                cnt+=yb[eend].a;
            }
            eend--;
        }
        else if(xb[start].a==yb[start].a){
            if(xb[start].c!=yb[eend].c){
                cnt+=yb[eend].a;
            }
            start++;
            eend--;
        }
        else{
            yb[eend].a-=xb[start].a;
            if(xb[start].c!=yb[eend].c){
                cnt+=xb[start].a;
            }
            start++;
        }
    }
    cout<<cnt;
    return 0;
}
//    for(int i=1;i<=2;i++){
//        cout<<xb[i].a<<" "<<xb[i].c<<" ";
//    }
//    for(int i=2;i<=3;i++){
//        cout<<yb[i].a<<" "<<yb[i].c<<" ";
//    }
