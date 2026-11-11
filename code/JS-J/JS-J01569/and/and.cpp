#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }if(m==2){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(a[i]&a[j],maxn);
            }
        }cout<<maxn;
        return 0;
    }if(m==3){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    maxn=max(a[i]&a[j]&a[z],maxn);
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==4){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        maxn=max(a[i]&a[j]&a[z]&a[x],maxn);
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==5){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            maxn=max(a[i]&a[j]&a[z]&a[x]&a[y],maxn);
                        }
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==6){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int k=y+1;k<=n;k++){
                                maxn=max(a[i]&a[j]&a[z]&a[x]&a[y]&a[k],maxn);
                            }
                        }
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==7){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int k=y+1;k<=n;k++){
                                for(int h=k+1;h<=n;h++){
                                    maxn=max(a[i]&a[j]&a[z]&a[x]&a[y]&a[k]&a[h],maxn);
                                }
                            }
                        }
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==8){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int k=y+1;k<=n;k++){
                                for(int h=k+1;h<=n;h++){
                                    for(int w=h+1;w<=n;w++){
                                        maxn=max(a[i]&a[j]&a[z]&a[x]&a[y]&a[k]&a[h]&a[w],maxn);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==9){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int k=y+1;k<=n;k++){
                                for(int h=k+1;h<=n;h++){
                                    for(int w=h+1;w<=n;w++){
                                        for(int r=w+1;r<=n;r++){
                                            maxn=max(a[i]&a[j]&a[z]&a[x]&a[y]&a[k]&a[h]&a[w]&a[r],maxn);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }if(m==10){
        long long maxn=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int x=z+1;x<=n;x++){
                        for(int y=x+1;y<=n;y++){
                            for(int k=y+1;k<=n;k++){
                                for(int h=k+1;h<=n;h++){
                                    for(int w=h+1;w<=n;w++){
                                        for(int r=w+1;r<=n;r++){
                                            for(int l=r+1;l<=n;l++){
                                                maxn=max(a[i]&a[j]&a[z]&a[x]&a[y]&a[k]&a[h]&a[w]&a[r]&a[l],maxn);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }cout<<maxn;
        return 0;
    }cout<<a[n];
	return 0;
}
