#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],ans=-1,cnt[39],v[200004][33];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int tp=a[i],cnt1=0;
        while(tp){
            if(tp%2){
                 cnt[cnt1]++;
                 v[i][cnt1]=1;
            }cnt1++;
            tp/=2;
        }
    }
    for(int i=30;i>=0;i--){
        if(cnt[i]>=m){
            int ttt=cnt[i],ok=i;
            vector<int>ppp;
            for(int j=1;j<=n;j++){
                if(v[j][i]){
                    ppp.push_back(j);
                }
            }
            while(ttt>m){
                bool f=0;
                for(int k=ok-1;k>=0;k--){
                    int tp1=0;
                    vector<int>ppp1;
                    for(int j:ppp){
                        if(v[j][k]){
                            tp1++;
                            ppp1.push_back(j);
                        }
                    }
                    if(tp1==m){
                        ok=k;
                        f=1;
                        ppp=ppp1;
                    }
                    if(tp1<ttt&&tp1>m){
                        ttt=tp1;
                        ok=k;
                        ppp=ppp1;
                    }if(k==0){
                        f=1;
                    }if(f) break;
                }if(f) break;
            }int pt=0;
            for(int j:ppp){
                if(v[j][ok]&&ans==-1){
                    ans=a[j];
                    pt=1;
                }else if(v[j][ok])ans&=a[j],pt++;
                if(pt==m) break;
            }
            printf("%d",ans);
            return 0;
        }
    }printf("0");
    return 0;
}
