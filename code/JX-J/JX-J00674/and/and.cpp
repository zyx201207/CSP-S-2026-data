#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
#define rep(i,l,r) for(long long i = l;i <= r;i++)
ll n,m,a[200005],ans,maxn = -1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    if(m == 1){
        cout << maxn;
        return 0;
    }
    if(m == 2){
        for(ll i = 1;i <= n;i++)
            for(ll j = i+1;j <= n;j++)
                ans = max(ans,a[i] & a[j]);
    }
    if(m == n){
        ans = a[1];
        for(ll i = 2;i <= n;i++)
            ans = ans & a[i];
    }
    if(m == 4){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        ans = max(ans,a[i]&a[j]&a[l]&a[r]);
    }
    if(m == 3){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    ans = max(ans,a[i]&a[j]&a[l]);
    }
    if(m == 5){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]);
    }
    if(m == 6){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]);
    }
    if(m == 7){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]);
    }
    if(m == 8){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]);
    }
    if(m == 9){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]);
    }
    if(m == 10){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]);
    }
    if(m == 11){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]);
    }
    if(m == 12){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]);
    }
    if(m == 13){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]);
    }
    if(m == 14){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]);
    }
    if(m == 15){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                rep(ss,rr+1,n)
                                                                    ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]&a[ss]);
    }
    if(m == 16){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                rep(ss,rr+1,n)
                                                                    rep(tt,ss+1,n)
                                                                        ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]&a[ss]&a[tt]);
    }
    if(m == 17){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                rep(ss,rr+1,n)
                                                                    rep(tt,ss+1,n)
                                                                        rep(kk,tt+1,n)
                                                                            ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]&a[ss]&a[tt]&a[kk]);
    }
    if(m == 18){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                rep(ss,rr+1,n)
                                                                    rep(tt,ss+1,n)
                                                                        rep(kk,tt+1,n)
                                                                            rep(uu,kk+1,n)
                                                                                ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]&a[ss]&a[tt]&a[kk]&a[uu]);
    }
    if(m == 19){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                rep(ss,rr+1,n)
                                                                    rep(tt,ss+1,n)
                                                                        rep(kk,tt+1,n)
                                                                            rep(uu,kk+1,n)
                                                                                rep(vv,uu+1,n)
                                                                                    ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]&a[ss]&a[tt]&a[kk]&a[uu]&a[vv]);
    }
    if(m == 20){
        rep(i,1,n)
            rep(j,i+1,n)
                rep(l,j+1,n)
                    rep(r,l+1,n)
                        rep(s,r+1,n)
                            rep(t,s+1,n)
                                rep(k,t+1,n)
                                    rep(u,k+1,n)
                                        rep(v,u+1,n)
                                            rep(z,v+1,n)
                                                rep(ii,z+1,n)
                                                    rep(jj,ii+1,n)
                                                        rep(l1l,jj+1,n)
                                                            rep(rr,l1l+1,n)
                                                                rep(ss,rr+1,n)
                                                                    rep(tt,ss+1,n)
                                                                        rep(kk,tt+1,n)
                                                                            rep(uu,kk+1,n)
                                                                                rep(vv,uu+1,n)
                                                                                    rep(zz,vv+1,n)
                                                                                        ans = max(ans,a[i]&a[j]&a[l]&a[r]&a[s]&a[t]&a[k]&a[u]&a[v]&a[z]&a[ii]&a[jj]&a[l1l]&a[rr]&a[ss]&a[tt]&a[kk]&a[uu]&a[vv]&a[zz]);
    }
    if(m <= 20 || m == n)
        cout << ans;
    else
        cout << maxn;
    return 0;
}
