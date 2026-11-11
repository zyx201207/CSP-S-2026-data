#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,u,ans=2147483647;
    scanf("%d%d",&n,&m);
    u=n;
    vector<int>a(n+1),s(25),aa(n+1),useful(n+1,1),yu;
    vector<vector<char>> w(n+1,vector<char>(25,0));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        aa[i]=a[i];
        int k=1,kk=1;
        while(aa[i]){
            if(aa[i]&k){
                w[i][kk]=1;
                s[kk]++;
                aa[i]^=k;
            }
            kk++;
            k<<=1;
        }
    }
    for(int i=20;i>0;i--){
        if(s[i]>=m){
            for(int j=1;j<=n;j++){
                if(useful[j]==-1){
                    useful[j]=0;
                    continue;
                }
                if(useful[j]==0){
                    continue;
                }
                if(w[j][i]==0){
                    useful[j]=-1;
                    u--;
                }
            }
        }
        if(u<=m){
            int p=m-u;
            for(int j=1;j<=n;j++){
                if(useful[j]==1){
                    ans&=a[j];
                }else if(useful[j]==-1 && p){
                    yu.push_back(j);
                }
            }
            if(p){
                sort(yu.begin(),yu.end(),greater<int>());
            }
            for(int j=0;j<p;j++){
                ans&=yu[j];
            }
            break;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
