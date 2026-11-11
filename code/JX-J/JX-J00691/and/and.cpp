#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++){
   //     cout<<a[i];
	//}
	if(m==1){
            long long ma=-1;
        for(int i=1;i<=n;i++){
            ma=max(a[i],ma);
        }
    cout<<ma;
    return 0;
	}
	if(m==2){
        long long ma=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma=max(a[i]&a[j],ma);
            }
        }
        cout<<ma;
        return 0;
	}
	if(m==n){
        long long an;
        an=a[1]&a[2];
        for(int i=1;i<=n;i++){
            an=an&a[i];
        }
    cout<<an;
    return 0;
	}
	if(m==n-1){
        long long ma=-1;
        for(int i=1;i<=n;i++){
                long long an;
                an=a[1]&a[2];
            for(int j=1;j<=n;j++){
                if(j!=i){
                    an=an&a[i];
                }
            }
            ma=max(an,ma);
        }
        cout<<ma;
        return 0;
	}
	long long an=a[n]&a[n-1];
    for(int i=n;i>0;i--){
        an=an&a[i];
    }
    cout<<an;
return 0;
}
