#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maw,st,ans;
vector <long long> co[35];
struct node{
    long long id;
    bool can;
};
vector <node> v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long w=0;
        while((a[i]>>w)!=0){
            if((a[i]>>w)&1==1) co[w].push_back(i);
            w++;
        }
        maw=max(maw,w-1);
    }
    if(n==m){
    	ans=a[1];
    	for(int i=2;i<=n;i++) ans&=a[i];
    	cout<<ans;
    	return 0;
	}
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
//    cout<<maw;
	st=-1;
    for(int i=maw;i>=0;i--){
        if(co[i].size()>m){
            st=i;
            break;
        }
        else if(co[i].size()==m){
            ans=a[co[i][0]];
            for(int j=1;j<m;j++) ans=ans&a[co[i][j]];
            cout<<ans;
            return 0;
        }
    }
    if(st==-1){
    	cout<<0;
    	return 0;
	}
    long long tot=co[st].size();
    for(int i=0;i<co[st].size();i++) v.push_back({co[st][i],true});
    for(int i=st-1;i>=0;i--){
    	if(co[i].size()==m){
            for(int j=0;j<v.size();j++){
                if(((a[v[j].id]>>i)&1)==0){
                    v[j].can=false;
                    tot--;
                }
                if(tot==m){
                    long long ans=INT_MAX;
                    for(int j=0;j<v.size();j++){
                        if(v[j].can) ans&=a[v[j].id];
                    }
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    long long ans=INT_MAX;
    for(int j=0;j<v.size();j++){
    	if(v[j].can) ans&=a[v[j].id];
	}
	cout<<ans;
    return 0;
}
