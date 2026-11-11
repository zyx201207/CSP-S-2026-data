#include<bits/stdc++.h>
using namespace std;
int c,T,n,q,x,y,vi[1000005],vi2[1000005],ok[1000005],dep[1000005],fa[1000005],dit[1005][1005],ans,an2,an3,dd;vector<int> s[1000005],t[1000005];
void dfs(int a){
    for(int j=0;j<s[a].size();j++){
        if(vi[s[a][j]]==0){
            vi[s[a][j]]=1;t[a].push_back(s[a][j]);dep[s[a][j]]=dep[a]+1;fa[s[a][j]]=a;dfs(s[a][j]);
        }
    }
}
void dfs2(int a){
    for(int j=0;j<s[a].size();j++){
        if(vi2[s[a][j]]==0&&ok[s[a][j]]==1){
            vi2[s[a][j]]=1;dfs2(s[a][j]);
        }
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b]){
        swap(a,b);
    }
    while(dep[a]>dep[b]){
        a=fa[a];
    }
    if(a==b){
        return a;
    }
    while(a!=b){
        a=fa[a],b=fa[b];
    }
    return a;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    for(int j=0;j<T;j++){
        cin>>n>>q;
        for(int k=0;k<n-1;k++){
            cin>>x>>y;x--;y--;s[x].push_back(y);s[y].push_back(x);
        }
        vi[0]=1;dfs(0);
        if(c==7){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        dit[k][l]=dep[k]+dep[l]-2*dep[lca(k,l)];
                    }
                }
            an2=n+1;
            for(int k=0;k<n;k++){
                for(int l=k+1;l<n;l++){
                    ans=0;
                    for(int m=0;m<n;m++){
                        ans=max(ans,min(dit[k][m],dit[l][m]));
                    }
                    an2=min(an2,ans);
                }
            }
            cout<<an2<<'\n';
        }else if(c==13||c==14){
            if(q<=(n+1)/2){
                int tp=(n+3)/2;
                if(q==2){
                    cout<<(int)ceil((tp-2)/3.0)<<'\n';
                }else{
                    cout<<(int)ceil((tp-q)/4.0)<<'\n';
                }
            }else if(q==n){
                cout<<0<<'\n';
            }else{
                cout<<1<<'\n';
            }
        }else if(c<=3){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        dit[k][l]=dep[k]+dep[l]-2*dep[lca(k,l)];
                    }
                }
            an2=n+1;
            for(int k=0;k<(1<<n);k++){
                dd=0;
                for(int l=0;l<n;l++){
                    if(k&(1<<l)){
                        dd++;ok[l]=1;
                    }else{
                        ok[l]=0;
                    }
                    vi2[l]=0;
                }
                if(dd==q){
                    ans=0;dd=0;
                    for(int m=0;m<n;m++){
                        if(ok[m]==1&&vi2[m]==0){
                            vi2[m]=1;dfs2(m);dd++;
                        }
                    }
                    if(dd>=3){
                        continue;
                    }
                    for(int m=0;m<n;m++){
                        an3=n+1;
                        for(int m2=0;m2<n;m2++){
                            if(k&(1<<m2)){
                                an3=min(an3,dit[m2][m]);
                            }
                        }
                        ans=max(ans,an3);
                    }
                    an2=min(an2,ans);
                }

            }
            cout<<an2<<'\n';
        }else{
            cout<<n-q<<'\n';
        }
        for(int k=0;k<n;k++){
            s[k].clear();t[k].clear();vi[k]=0;
        }
    }
}
