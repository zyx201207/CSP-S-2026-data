#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	bool A=true,B=true;
	ll cha=0;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)A=false;
        if(i==2)cha=a[i]-a[i-1];
        else if(i>2){
            if(a[i]-a[i-1]!=cha)B=false;
        }
	}
	if(A){
        ll cost=0;
        for(int i=1;i<n;i++){
            cost+=i;
            if(cost>m){
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
	}
	if(B){
        ll cost=0;
        for(int i=1;i<n;i++){
            cost+=cha*i;
            if(cost>m){
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
	}
	sort(a.begin()+1,a.end());
	int ans=1;
	for(int i=2;i<=n;i++){
        int j=i-1,cost=0,flag=0;
        while(j>=1){
            cost+=a[i]-a[j];
            if(cost>m){
                ans=max(ans,i-j);
                flag=1;
                break;
            }
            j--;
        }
        if(!flag)ans=max(ans,i);
	}
	cout<<ans;
    return 0;
}
