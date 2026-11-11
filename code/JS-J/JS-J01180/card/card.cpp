#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=b-1;i>=a;i--)
int n,m,pos,a[500007],l[500007],r[500007],cnt[300007],ans[300007];
void Cnt(){
    int num=0;
    while(r[num]!=0){
        num=r[num];
        ans[a[num]]++;
    }
}
void out(){
    int num=0;
    while(r[num]!=0){
        num=r[num];
        cout<<a[num]<<" ";
    }
    cout<<endl;
}
void del(int x){
    int num=l[x];
    while(r[num]!=0){
        num=r[num];
        cnt[a[num]]--;
    }
    r[l[x]]=0;
    l[0]=l[x];
}
int fid(int x){
    int num=0;
    while(r[num]!=0){
        num=r[num];
        //if(a[x]==3)cout<<"!!! "<<a[num]<<" "<<a[x]<<endl;
        if(a[num]==a[x])return num;
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    fr(i,1,n+1)cin>>a[i];
    fr(I,1,n+1){
        fr(i,I,n+1){
            //cout<<"!!! "<<a[i]<<endl;
            if(cnt[a[i]]==0){
                r[l[0]]=i;
                l[i]=l[0];
                r[i]=0;
                l[0]=i;
                cnt[a[i]]++;
            }
            else{
                del(fid(i));
                r[l[0]]=i;
                l[i]=l[0];
                r[i]=0;
                l[0]=i;
                cnt[a[i]]++;
            }
            //out();
        }
        //out();
        Cnt();
        del(r[0]);
        //out();
    }
    fr(i,1,m+1)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
