#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
long long cry[maxn];
int n,m;
int ans=1;
int main(){
   // freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>cry[i];
    sort(cry,cry+n);




    if(n>5000){
        if(cry[2]-cry[1]==cry[3]-cry[2]&&cry[4]-cry[3]==cry[3]-cry[2]&&cry[5]-cry[4]==cry[4]-cry[3]){
            int k=cry[2]-cry[1];
            while(1){
                if(m-k<0)break;
                m=m-k;
                k=k+cry[2]-cry[1];
                ans++;
            }
        }
        else{
        int mid=1+n>>1;
            int mm=m;

            while(1){
                int l=mid-1,r=mid+1;
                if(abs(cry[mid]-cry[l])<=abs(cry[r]-cry[mid])){
                        if(mm-cry[mid]+cry[l]<0) break;
                        mm=mm-cry[mid]+cry[l--];
                        ans++;
                }
                else {
                    if(mm-cry[mid]+cry[r]<0) break;
                    mm=mm-cry[r++]+cry[mid];
                    ans++;
                }
            }
        }
    }


    if(n<=5000) {

        for(int u=1;u<=n;u++){
            int sum=0;
            int cur[maxn];
            for(int i=1;i<=n;i++)
                cur[i]=abs(cry[u]-cry[i]);
            int b=1;
            sort(cur,cur+n);
            while(1){
                if(m-cur[b]<0)break;
                    m=m-cur[b++];
                    sum++;
            }
            ans=max(ans,sum);
        }


   }


    cout<<ans;

    return 0;
}








