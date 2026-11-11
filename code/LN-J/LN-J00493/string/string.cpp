#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
struct node{
    int number;
    char ch;
}a[200005];

int i=1,j;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
j=n;
for(int i=1;i<=n;i++)cin>>a[i].number>>a[i].ch;
//cout<<i<<' '<<j<<endl;
while(i!=j){
    //cout<<a[i].number<<' '<<i<<' '<<a[i].ch<<' '<<a[j].number<<' '<<j<<' '<<a[j].ch<<' '<<cnt<<endl;
    if(a[i].ch==a[j].ch){
        int m=min(a[i].number,a[j].number);
        a[i].number-=m;
        a[j].number-=m;
        if(a[i].number==0)i++;
        if(a[j].number==0)j--;
        continue;
    }
        int m=min(a[i].number,a[j].number);
        cnt+=m;
        a[i].number-=m;
        a[j].number-=m;
        if(a[i].number==0)i++;
        if(a[j].number==0)j--;
    if(i>n)break;

}
cout<<cnt;
return 0;
}
