/*#include<bits/stdc++.h>
using namespace std;
struct numbers{
    long long a;
    int shuwei;
};
bool cmp(numbers first,numbers second){
    if(first.shuwei>second.shuwei)
        return first.shuwei>second.shuwei;
    if(first.shuwei<second.shuwei)
        return first.shuwei<second.shuwei;
    else{
        if(first.a>second.a)
            return first.shuwei>second.shuwei;
        else
            return first.shuwei<second.shuwei;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int maxn_digit=0;
    numbers CCF[n];
    for(int i=0;i<n;++i){
        cin>>CCF[i].a;
        int m=CCF[i].a;
        while(m>0){
            m/=2;
            CCF[i].shuwei++;
        }
    }
    sort(CCF,CCF+n,cmp);
    int digits[maxn_digit];
}
*/
#include<bits/stdc++.h>
using namespace std;
/*struct cardd{
    int number;
    int seat;
    int ans;
};
int solve(cardd cards[],int now){
    for(int i=now-1;i<n;++i){
        if(cards[cards[i].number].seat==0)
            cards[cards[i].number].seat=i;
        else{
            for(int m= cards[cards[i].number].seat;m<i;++m)
                 cards[m].seat=0;
            cards[cards[i].number].seat=0;
        }
    }
    if(cards[i].seat!=0)
        cards[i].ans++;
}*/
int main(){
    /*int n,m;
    cin>>n>>m;
    char a[n];
    string leaved;
    cardd cards[300005];
    for(int i=0;i<n;++i){
        cin>>cards[i].number;
    }
    for(int i=0;i<m;++i){
        solve(cards,i);
    }
    for(int i=0;i<m;++i)
        cout<<cards[i].ans;*/
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[m-1];
}
