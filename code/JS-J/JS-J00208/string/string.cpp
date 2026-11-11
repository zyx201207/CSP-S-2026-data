#include<bits/stdc++.h>
using namespace std;
int t,x,k,kb,r,c;
string s1,s2,y;
struct str{
    int num;
    string st;
}v[100010];
vector<int> a;
long long q[100010];
long long s,b;
int main(){
    //freopen("string.in","r",stdin);
   //freopen("string.out","w",stdout);
    scanf("%d",&t);
    int tt=t;
    for(int i=1;i<=tt;i++){
        scanf("%d",&x);
        scanf("%s",&y);
       // if(y==a[i-1].st){}

        v[i].num=x;
        v[i].st=y;

        s+=x;
    }
    a.push_back(v[1].num);
    for(int i=2;i<=t;i++){
        if(v[i].st==v[i-1].st){

            a[i-1]+=a[i];
            c++;
        }else{
            a.push_back(v[i].num);
        }
    }
    t-=c;

    //cout<<t<<" ";
    for(int i=1;i<=t;i++){
        q[i]=q[i-1]+a[i];
    }
    if(s%2==0){
        b=s/2;
        for(int i=1;i<=t;i++){
            if(q[i]>b){
                r=i;
                break;
            }
        }
        cout<<max(s-b-(q[r]-b),s-b-(b-q[r-1]));
    }
    else{
        b=s/2+1;
     //   cout<<t<<" ";
        for(int i=1;i<=t;i++){
          //  cout<<q[i]<<" ";
            if(q[i]>b){

                r=i;
                break;
            }
        }
     //   cout<<b<<" "<<r<<" ";

        cout<<max(s-b-(b-q[r-1])+1,s-b-(q[r]-b));
    }

    cout<<endl;
    return 0;
}
