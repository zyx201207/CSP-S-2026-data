#include<bits/stdc++.h>
using namespace std;
int maxx=0;
int Max;
int ab;
int a[1000007],m,n;
int minn=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int cns=m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
    	cout<<a[0];
    	return 0;
	}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                swap(a[j],a[i]);
            }
        }
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int maxx=max((a[i]&a[j]),minn);
                minn=maxx;
            }
        }
        cout<<maxx;
    }else{
        for(int i=0;i<n;i++){
            ab=(a[i+m-1]&a[i+m-2]);
            m--;
            if(m){
                Max=ab&a[i+m-2];
                continue;
            }
        }
        cout<<Max;
    }
    return 0;
}
