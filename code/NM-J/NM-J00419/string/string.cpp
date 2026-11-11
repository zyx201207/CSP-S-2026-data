#include<bits/stdc++.h>
using namespace std;
pair<char,int>a[10000];
int main(){
    // freopen("string.in","r",stdin);
    // freopen("string.out","w",stdout);
    int n,cnt=0,ans=0;
    scanf("%d",&n);
    const int N=n;
    for(int i=0;i<N;i++){
        const int I=i;
        int c;
        char b;
        scanf("%d %c",&b,&c);
        a[I].first=b;
        a[I].second=c;
        cnt+=c;
    }
    cout<<1;
    cnt/=2;
    int j=1;
    int i=0;
        while(i!=N-j){cout<<i<<' '<<N<<endl;
            if(a[i].first==a[n-j].first){
                if(a[i].second==a[n-j].second){
                    i++;
                    j++;
                    cnt-=a[i].second;



                }
                else if(a[i].second>a[N-j].second){
                    a[i].second-=a[N-j].second;
                    j++;



                }
                else{
                    a[N-j].second-=a[i].second;
                    i++;
                    cnt-=a[i].second;



                }
            }
            else{
                if(a[i].second==a[N-j].second){
                    i++;
                    j++;
                    ans+=a[i].second;
                    cnt-=a[i].second;


                }
                else if(a[i].second>a[n-j].second){
                    a[i].second-=a[n-j].second;
                    j++;
                    ans+=a[N-j].second;



                }
                else{
                    a[n-j].second-=a[i].second;
                    i++;
                    ans+=a[i].second;
                    cnt-=a[i].second;


                }
            }
            if(cnt<0)break;

        }
        cout<<ans;
    // for(int i=0;i<=cnt;i++){

    // }

    return 0;

}
