#include<bits/stdc++.h>
using namespace std;
int a[200010];
struct node{
    int x,v,num;
}dl[1000010];
int main(){
    freopen("and1.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,ans=-2147483647;
    int head=1,tail=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dl[tail].v=a[i];
        dl[tail].num=1;
        dl[tail].x=i;
        tail++;
    }
    while(head<=tail){
        cout<<head<<" "<<tail<<endl;
        if(dl[head].num==m){
            ans=max(ans,dl[head].v);
        }
        else{
            cout<<dl[head].x<<"         ";
            for(int i=dl[head].x+1;i<=n;i++){
                /*dl[tail].v=(dl[head].v&a[i]);*/
                dl[tail].num=dl[head].num+1;
                dl[tail].x=i;
                tail++;
            }
        }
        head++;
    }
        for(int i=1;i<=n;i++){
        //cin>>a[i];
        cout<<dl[i].v<<"   ";
        cout<<dl[i].num<"    ";
        cout<<dl[i].x<<"     ";
        //tail++;
    }
    cout<<ans;
}
