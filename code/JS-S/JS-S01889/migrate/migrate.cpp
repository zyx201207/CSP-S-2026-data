#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        ll d;
        cin>>n>>d;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> p(n),q(n);
        for(int i=0;i<n;i++){
            int l1=0,r1=i;
            p[i]=i;
            while(l1<=r1){
                int mid=l1+(r1-l1)/2;
                if(a[i]-a[mid]<=d) r1=mid-1,p[i]=mid;
                else l1=mid+1;
            }
            int l2=i,r2=n-1;
            q[i]=i;
            while(l2<=r2){
                int mid=l2+(r2-l2)/2;
                if(a[mid]-a[i]<=d) l2=mid+1,q[i]=mid;
                else r2=mid-1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(q[i]>i+1){
                for(int j=0;j<n;j++){
                    if(p[j]<j-1){
                        if(q[i]==p[j]+1){
                            int l=i,r=j;
                            while(l&&a[l-1]+d==a[l]) l--;
                            while(r!=n-1&&a[r+1]-d==a[r]) r++;
                            //cout<<l<<' '<<r<<'\n';
                            ans+=(i-l+1)*(r-j+1);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
        /*set<pair<int,int> > st;
        for(int i=0;i<n;i++){
            int l1=0,r1=i,p=i;
            while(l1<=r1){
                int mid=l1+(r1-l1)/2;
                if(a[i]-a[mid]<=d) r1=mid-1,p=mid;
                else l1=mid+1;
            }
            int l2=i,r2=n-1,q=i;
            while(l2<=r2){
                int mid=l2+(r2-l2)/2;
                if(a[mid]-a[i]<=d) l2=mid+1,q=mid;
                else r2=mid-1;
            }
            if(q-p+1==3){
                if(p&&a[p]-a[p-1]<=d) st.insert(make_pair(p-1,q));
                if(q!=n-1&&a[q+1]-a[q]<=d) st.insert(make_pair(p,q+1));
            }
        }
        cout<<st.size()<<'\n';*/
        //5 3
        //-3 0 2 3 4
        //2
    }
}
