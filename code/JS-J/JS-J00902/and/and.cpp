#include <bits/stdc++.h>
using namespace std;
int m,n,cc0,cc1,cc2,cc3;
pair<int,int> a[500005];
void task1to5(){
    int ans=-1;
    sort(a+1,a+n+1);
    do{
        int now=a[1].first;
        for(int i=2;i<=m;i++)now&=a[i].first;
        ans=max(ans,now);
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<endl;
}
void task6(){
    sort(a+1,a+n+1);
    cout<<a[n].first<<endl;
}
void task7(){
    int ans=a[1].first;
    for(int i=2;i<=n;i++)ans&=a[i].first;
    cout<<ans<<endl;
}
void task8to10(){
    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i].first&a[j].first);
        }
    }
    cout<<ans<<endl;
}
void task16to17(){
    if(cc3>=m)cout<<3<<endl;
    else if(cc3+cc2>=m)cout<<2<<endl;
    else if(cc3+cc1>=m)cout<<1<<endl;
    else cout<<0<<endl;
}
bool flag=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
        switch(a[i].first){
            case 0:{cc0++;break;}
            case 1:{cc1++;break;}
            case 2:{cc2++;break;}
            case 3:{cc3++;break;}
            default:flag=false;
        }
    }
    if(n<=20)task1to5();
    else if(m==1)task6();
    else if(m==n)task7();
    else if(m==2)task8to10();
    else if(flag)task16to17();
    return 0;
}
/*
10001
01000
00111
*/
