#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
struct st{
    long long numb;
    char lett;
}stringg[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stringg[i].numb>>stringg[i].lett;
        cnt+=stringg[i].numb;
    }
    cnt/=2;
    long long i=1,j=0;
    while(cnt>0){
        long long jian=min(stringg[n-j].numb,stringg[i].numb);
        if(stringg[n-j].lett==stringg[i].lett){
            if(cnt>=jian)cnt-=jian;
            else break;
        }
        else{
            if(cnt>=jian){
                cnt-=jian;
                ans+=jian;
            }
            else{
                ans+=cnt;
                break;
            }
        }
        if(stringg[n-j].numb<stringg[i].numb){
                stringg[i].numb-=stringg[n-j].numb;
                stringg[n-j].numb=0;
                j++;
            }
            else if(stringg[n-j].numb==stringg[i].numb){
                stringg[i].numb=0;
                stringg[n-j].numb=0;
                j++;
                i++;
            }
            else if(stringg[n-j].numb>stringg[i].numb){
                stringg[n-j].numb-=stringg[i].numb;
                stringg[i].numb=0;
                i++;
            }
    }
    cout<<ans;
    return 0;
}
