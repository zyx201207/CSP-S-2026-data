#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll yu[N];
int n,m;
ll ans=0;
bool vis[N];
void dfs(int depth,ll cnt){
    if(depth+1==m){
        ans=max(ans,cnt);
        return;
    }
    for(int i=depth+1;i<=n;i++){
        if(vis[i]==0){
                vis[i]=1;
            dfs(depth+1,cnt&yu[depth]);
        vis[i]=0;
        }

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&yu[i]);
    }
    sort(yu+1,yu+n+1,greater<int>());
        if(m==1){
            ll maxn=0;
            for(int i=1;i<=n;i++){
                maxn=max(maxn,yu[i]);
            }
            cout<<maxn;
            return 0;
        }
        else if(m==n){
            ll ans2=yu[1];
            for(int i=2;i<=n;i++){
                ans2&=yu[i];
            }
            cout<<ans2;
            return 0;
        }
        else if(m==2){
            long long ans3=0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    ans3=max(ans3,yu[i]&yu[j]);
                }
            }
            cout<<ans3;
            return 0;
        }
    else if(m==3){
        long long ans3=0;
        for(int i=1;i+2<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int k=j+1;k<=m;k++){
                    ans3=max(ans3,yu[i]&yu[j]&yu[k]);
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==4){
            long long ans3=0;
        for(int a=1;a+3<=n;a++){
            for(int b=a+1;b+2<=n;b++){
                for(int c=b+1;c+1<=n;c++){
                    for(int d=c+1;d<=n;d++){
                            ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]);
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==5){
        long long ans3=0;
        for(int a=1;a+4<=n;a++){
            for(int b=a+1;b+3<=n;b++){
                for(int c=b+1;c+2<=n;c++){
                    for(int d=c+1;d+1<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]);
                        }
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==6){
        long long ans3=0;
        for(int a=1;a+5<=n;a++){
            for(int b=a+1;b+4<=n;b++){
                for(int c=b+1;c+3<=n;c++){
                    for(int d=c+1;d+2<=n;d++){
                        for(int e=d+1;e+1<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]);
                            }
                        }
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==7){
        long long ans3=0;
        for(int a=1;a+6<=n;a++){
            for(int b=a+1;b+5<=n;b++){
                for(int c=b+1;c+4<=n;c++){
                    for(int d=c+1;d+3<=n;d++){
                        for(int e=d+1;e+2<=n;e++){
                            for(int f=e+1;f+1<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==8){
        long long ans3=0;
        for(int h=1;h+7<=n;h++){
            for(int a=h+1;a+6<=n;a++){
                for(int b=a+1;b+5<=n;b++){
                    for(int c=b+1;c+4<=n;c++){
                        for(int d=c+1;d+3<=n;d++){
                            for(int e=d+1;e+2<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g<=n;g++){
                                        ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==9){
        long long ans3=0;
        for(int i=1;i+8<=n;i++){
            for(int h=i+1;h+7<=n;h++){
                for(int a=h+1;a+6<=n;a++){
                    for(int b=a+1;b+5<=n;b++){
                        for(int c=b+1;c+4<=n;c++){
                            for(int d=c+1;d+3<=n;d++){
                                for(int e=d+1;e+2<=n;e++){
                                    for(int f=e+1;f+1<=n;f++){
                                        for(int g=f+1;g<=n;g++){
                                            ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==10){
        long long ans3=0;
        for(int j=1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==11){
        long long ans3=0;
        for(int k=1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==12){
        long long ans3=0;
        for(int l=1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==13){
        long long ans3=0;
        for(int o=1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==14){
        long long ans3=0;
        for(int p=1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==15){
        long long ans3=0;
        for(int q=1;q+14<=n;q++){
            for(int p=q+1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]&yu[q]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==16){
        long long ans3=0;
        for(int r=1;r+15<=n;r++){
            for(int q=r+1;q+14<=n;q++){
            for(int p=q+1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]&yu[q]&yu[r]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        }
        }
        cout<<ans3;
        return 0;
    }
    else if(m==17){
        long long ans3=0;
        for(int s=1;s+16<=n;s++){
            for(int r=s+1;r+15<=n;r++){
            for(int q=r+1;q+14<=n;q++){
            for(int p=q+1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]&yu[q]&yu[r]&yu[s]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        }
        }
        }

        cout<<ans3;
        return 0;
    }
    else if(m==18){
        long long ans3=0;
        for(int t=1;t+17<=n;t++){
            for(int s=t+1;s+16<=n;s++){
            for(int r=s+1;r+15<=n;r++){
            for(int q=r+1;q+14<=n;q++){
            for(int p=q+1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]&yu[q]&yu[r]&yu[s]&yu[t]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        }
        }
        }

        }

        cout<<ans3;
        return 0;
    }
    else if(m==19){
        long long ans3=0;
        for(int u=1;u+18<=n;u++){
            for(int t=u+1;t+17<=n;t++){
            for(int s=t+1;s+16<=n;s++){
            for(int r=s+1;r+15<=n;r++){
            for(int q=r+1;q+14<=n;q++){
            for(int p=q+1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]&yu[q]&yu[r]&yu[s]&yu[t]&yu[u]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        }
        }
        }

        }

        }

        cout<<ans3;
        return 0;
    }
    else if(m==20){
        long long ans3=0;
        for(int w=1;w+19<=n;w++){
            for(int u=w+1;u+18<=n;u++){
            for(int t=u+1;t+17<=n;t++){
            for(int s=t+1;s+16<=n;s++){
            for(int r=s+1;r+15<=n;r++){
            for(int q=r+1;q+14<=n;q++){
            for(int p=q+1;p+13<=n;p++){
            for(int o=p+1;o+12<=n;o++){
            for(int l=o+1;l+11<=n;l++){
            for(int k=l+1;k+10<=n;k++){
            for(int j=k+1;j+9<=n;j++){
              for(int i=j+1;i+8<=n;i++){
                for(int h=i+1;h+7<=n;h++){
                    for(int a=h+1;a+6<=n;a++){
                        for(int b=a+1;b+5<=n;b++){
                            for(int c=b+1;c+4<=n;c++){
                                for(int d=c+1;d+3<=n;d++){
                                    for(int e=d+1;e+2<=n;e++){
                                        for(int f=e+1;f+1<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                ans3=max(ans3,yu[a]&yu[b]&yu[c]&yu[d]&yu[e]&yu[f]&yu[g]&yu[h]&yu[i]&yu[j]&yu[k]&yu[l]&yu[o]&yu[p]&yu[q]&yu[r]&yu[s]&yu[t]&yu[u]&yu[w]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }
        }
        }
        }
        }
        }
        }

        }

        }
        }


        cout<<ans3;
    }
    return 0;
}
