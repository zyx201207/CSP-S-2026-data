#include <bits/stdc++.h>
using namespace std;
long long a[500100],n,m,s=1,c,cj,ans=INT_MIN;
bool b,b1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)b=1;
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i])b1=1;
        c=a[i]-a[i-1];
	}
	if(b==0){
        for(long long i=1;;i++){
            if(m-i<0||s==n)break;
            m-=i;s++;
        }
        cout<<s;
        return 0;
	}
	if(b1==0){
        m=1.0*m/c;
        for(long long i=1;;i++){
            if(m-i<0||s==n)break;
            m-=i;s++;
        }
        cout<<s;
        return 0;
	}
	s=1;
	for(long long i=2;i<=n;i++){
        for(long long j=i;j>=1;j--){
            cj=a[j]-a[j-1];
            if(cj<=m){
                a[j-1]+=cj;
                m-=cj;
                s++;
            }else break;
        }
        ans=max(ans,s);
        s=1;
	}
	cout<<ans;
	return 0;
}
