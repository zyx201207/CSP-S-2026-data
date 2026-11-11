#include<bits/stdc++.h>
using namespace std;
int n,m;int a[200001],ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m>20){
        cout<<n-m;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                int cnt=a[a1]&a[b];
                ans=max(ans,cnt);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==3){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    int cnt=a[a1]&a[b]&a[c];
                    ans=max(ans,cnt);
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==4){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        int cnt=a[a1]&a[b]&a[c]&a[d];
                        ans=max(ans,cnt);
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==5){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            int cnt=a[a1]&a[b]&a[c]&a[d]&a[e];
                            ans=max(ans,cnt);
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==6){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f];
                                ans=max(ans,cnt);
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==7){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g];
                                    ans=max(ans,cnt);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==8){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h];
                                        ans=max(ans,cnt);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==9){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i];
                                            ans=max(ans,cnt);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==10){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j];
                                                ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==11){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k];
                                                    ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
     if(m==12){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l];
                                                        ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==13){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o];
                                                            ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==14){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
                                                                ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==15){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                for(int q=p+1;q<=n;q++){
                                                                    int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
                                                                    ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==16){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                for(int q=p+1;q<=n;q++){
                                                                    for(int r=q+1;r<=n;r++){
                                                                        int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
                                                                        ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==17){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                for(int q=p+1;q<=n;q++){
                                                                    for(int r=q+1;r<=n;r++){
                                                                        for(int s=r+1;s<=n;s++){
                                                                            int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
                                                                            ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==18){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                for(int q=p+1;q<=n;q++){
                                                                    for(int r=q+1;r<=n;r++){
                                                                        for(int s=r+1;s<=n;s++){
                                                                            for(int t=s+1;t<=n;t++){
                                                                                int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
                                                                                ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==19){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                for(int q=p+1;q<=n;q++){
                                                                    for(int r=q+1;r<=n;r++){
                                                                        for(int s=r+1;s<=n;s++){
                                                                            for(int t=s+1;t<=n;t++){
                                                                                for(int u=t+1;u<=n;u++){
                                                                                    int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u];
                                                                                    ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    if(m==20){
        for(int a1=1;a1<=n;a1++){
            for(int b=a1+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                for(int k=j+1;k<=n;k++){
                                                    for(int l=k+1;l<=n;l++){
                                                        for(int o=l+1;o<=n;o++){
                                                            for(int p=o+1;p<=n;p++){
                                                                for(int q=p+1;q<=n;q++){
                                                                    for(int r=q+1;r<=n;r++){
                                                                        for(int s=r+1;s<=n;s++){
                                                                            for(int t=s+1;t<=n;t++){
                                                                                for(int u=t+1;u<=n;u++){
                                                                                    for(int v=u+1;v<=n;v++){
                                                                                        int cnt=a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v];
                                                                                        ans=max(ans,cnt);
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
        cout<<ans;
        return 0;
    }
    return 0;
}
