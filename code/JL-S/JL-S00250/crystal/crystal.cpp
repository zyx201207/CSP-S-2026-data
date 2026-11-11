#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e18;
int n,m,ans=1;
struct A{
	long long a,c;
}b[N];
bool cmp(A aa,A ab){
	return aa.a<ab.a;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	    cin>>b[i].a;
    }
    sort(b,b+n,cmp);
    b[n].c=0;
    for(int i=1;i<n;i++){
        b[i].c=b[i+1].a-b[i].a;
    }
    for(int j=1;j<=n;j++){
	    if(b[j].c*j>m) break;
	    m-=b[j].c*j;
	    ans++;
	}
    cout<<ans<<endl;
    return 0;
}
