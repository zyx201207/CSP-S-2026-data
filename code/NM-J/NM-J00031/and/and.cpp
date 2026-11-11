#include<iostream>
#include<algorithm>
#include<cmath> //an wei yu shi sha?
using namespace std;
const int N=2*1e5+2;
int cnt;
long long n,m,a[N],b[N];
//{1,3,7,15,31,63,127,255,511,1023,2047,4095,8191}
bool cmp(long long x,long long y){
    return x>y;
}
int pd(long long x){
    for(int i=0;i<=20;i++){
        if(x>pow(2,i)-1&&x<pow(2,i+1)-1){
            return -1;
        }
        if(x==pow(2,i)-1){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int tmp=pd(a[i]);
        if(tmp!=-1){
            b[cnt]=tmp;
            a[i]=0;
            cnt++;
        }
    }
    sort(a+1,a+n+1,cmp);
    sort(b,b+cnt,cmp);
    if(m==1){
        if(a[1]>pow(2,b[0])-1) cout<<a[1];
        else cout<<pow(2,b[0])-1;
        return 0;
        //ceshidian7 you na xia 5pts haha;
    }
    if(cnt==n){
        cout<<pow(2,b[m-1])-1;
        return 0;
        //te shu A
        //ying gai neng pian 5pts )) haha
    }
    if(m==n){
        long long tmp1=0;
        long long tmp2=pow(2,b[cnt-1])-1;;
        for(int i=1;i<=n+1;i++){
            if(a[i]==0){
                tmp1=a[i-1];
                break;
            }
        }
        if(tmp2<tmp1&&tmp2!=1){
            cout<<tmp2;
        }else{
            cout<<tmp1;
        }
        return 0;
    }
    if(pd(n)!=-1){
        cout<<a[1];//B xing zhi kanbu chu lai le jiu zhe yang ba
    }
    cout<<1;//ce shi 16 17 qiuqiu jiandanyidianba
    return 0;
}
