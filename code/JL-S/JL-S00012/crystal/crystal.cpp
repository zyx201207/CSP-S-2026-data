#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long s[500010];
long long q[500010];
long long hh,tt;
long long ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
	}
	long long sum=m,cnt=1;
	hh++;
	q[++tt]=1;
	for(int i=2;i<=n;i++){
        //for(int j=hh;j<=tt;j++){
        //    cout<<q[j]<<" ";
        //}
        //cout<<"\n\n";
        //cout<<sum<<" "<<cnt<<"\n";
        while(hh<=tt&&sum-s[i]*cnt<0){
            sum+=a[i-1]-a[q[hh]];
            hh++;
            cnt--;
        }
        q[++tt]=i;
        sum-=s[i]*cnt;
        cnt++;
        ans=max(ans,cnt);
	}
	cout<<ans;
    return 0;
}
