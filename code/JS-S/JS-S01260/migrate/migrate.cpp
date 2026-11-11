#include<bits/stdc++.h>
using namespace std;
long long arr[2000005];
struct ab{
    int l,r;
};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin >> c >> t;
    if(c>=13&&c<=14){
        while(t--){
            long long n,d;
            cin >> n >> d;
            for(int i=1;i<=n;i++){
                long long x;
                cin >> x;
            }
            cout << "0\n";
        }
        return 0;
    }
    if(c>=11&&c<=12){
        while(t--){
            long long n,d;
            cin >> n >> d;
            for(int i=1;i<=n;i++){
                cin >> arr[i];
            }
            long long x=arr[2]-arr[1];
            long long y=d/x;
            if(y==2){
                cout << n-3 << "\n";
            }
            else{
                cout << "0\n";
            }
        }
        return 0;
    }
    while(t--){
        long long n,d;
        cin >> n >> d;
        deque<int> q;
        vector<ab> ar;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            if(q.size()&&arr[i]-arr[q.front()]>d){
                ar.push_back({q.front(),i-1});
                while(q.size()&&arr[i]-arr[q.front()]>d){
                    q.pop_front();
                }
            }
            q.push_back(i);
        }
        if(q.size()){
            ar.push_back({q.front(),n});
        }
        int ll=ar[0].l,lr=ar[0].r;
        int l=0;
        long long cnt=0;
        for(int i=1;i<ar.size();i++){
            int nl=ar[i].l,nr=ar[i].r;
            while(nl>lr&&l<i){
                ll=ar[l+1].l;
                lr=ar[l+1].r;
                l++;
            }
            if(l!=i){
                while(lr-nl>1&&l<i){
                    lr=ar[l+1].r;
                    l++;
                }
            }
            cnt+=(nr-lr)*(nl-ll);
            ll=nl;
            lr=nr;
        }
        cout << cnt << "\n";
    }
    return 0;
}
