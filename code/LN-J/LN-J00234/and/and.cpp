#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma;
long long ans,zhong;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ma=-999;
    zhong=0;
    bool x4=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4)x4=0;
        ma=max(ma,a[i]);
        zhong=zhong&a[i];
    }
    if(x4){
        int y0=0,y1=0,y2=0,y3=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)y0=1;
            if(a[i]==1)y1=1;
            if(a[i]==2)y2=1;
            if(a[i]==3)y3=1;
        }
        if(!y1&&!y2&&!y3)cout<<0;
        else if(y1&&!y2&&!y3)cout<<1;
        else if((y1&&y2)||y3)cout<<3;
        else if(!y1&&y2&&!y3)cout<<2;
        return 0;
    }
    ans=-99999;
    if(n==m){
        cout<<zhong;
        return 0;
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    ans=max(ans,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        ans=max(ans,a[i]&a[j]&a[k]&a[x]);
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            ans=max(ans,a[i]&a[j]&a[k]&a[x]&a[y]);
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==6){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                ans=max(ans,a[i]&a[j]&a[k]&a[x]&a[y]&a[z]);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    ans=max(ans,a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        ans=max(ans,a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d];
                                            ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e];
                                                ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f];
                                                    ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g];
                                                        ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h];
                                                            ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz];
                                                                ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                for(int zsz=lxz+1;zsz<=n;zsz++){
                                                                    long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz]&a[zsz];
                                                                    ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                for(int zsz=lxz+1;zsz<=n;zsz++){
                                                                    for(int zwz=zsz+1;zwz<=n;zwz++){
                                                                        long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz]&a[zsz]&a[zwz];
                                                                        ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                for(int zsz=lxz+1;zsz<=n;zsz++){
                                                                    for(int zwz=zsz+1;zwz<=n;zwz++){
                                                                        for(int ii=zwz+1;ii<=n;ii++){
                                                                            long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz]&a[zsz]&a[zwz]&a[ii];
                                                                            ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                for(int zsz=lxz+1;zsz<=n;zsz++){
                                                                    for(int zwz=zsz+1;zwz<=n;zwz++){
                                                                        for(int ii=zwz+1;ii<=n;ii++){
                                                                            for(int jj=ii+1;jj<=n;jj++){
                                                                                long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz]&a[zsz]&a[zwz]&a[ii]&a[jj];
                                                                                ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                for(int zsz=lxz+1;zsz<=n;zsz++){
                                                                    for(int zwz=zsz+1;zwz<=n;zwz++){
                                                                        for(int ii=zwz+1;ii<=n;ii++){
                                                                            for(int jj=ii+1;jj<=n;jj++){
                                                                                for(int kk=jj+1;kk<=n;kk++){
                                                                                    long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz]&a[zsz]&a[zwz]&a[ii]&a[jj]&a[kk];
                                                                                    ans=max(ans,abcd);
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
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=k+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int z=y+1;z<=n;z++){
                                for(int w=z+1;w<=n;w++){
                                    for(int c=w+1;c<=n;c++){
                                        for(int d=c+1;d<=n;d++){
                                            for(int e=d+1;e<=n;e++){
                                                for(int f=e+1;f<=n;f++){
                                                    for(int g=f+1;g<=n;g++){
                                                        for(int h=g+1;h<=n;h++){
                                                            for(int lxz=h+1;lxz<=n;lxz++){
                                                                for(int zsz=lxz+1;zsz<=n;zsz++){
                                                                    for(int zwz=zsz+1;zwz<=n;zwz++){
                                                                        for(int ii=zwz+1;ii<=n;ii++){
                                                                            for(int jj=ii+1;jj<=n;jj++){
                                                                                for(int kk=jj+1;kk<=n;kk++){
                                                                                    for(int xx=kk+1;xx<=n;xx++){
                                                                                        long long abcd=a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[w]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[lxz]&a[zsz]&a[zwz]&a[ii]&a[jj]&a[kk]&a[xx];
                                                                                        ans=max(ans,abcd);
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
