#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long b[5005][5005],xo,c,xx,ss,d,dc=1;
bool v=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==i){
			c++;
		}
		ss+=a[i];
		if(ss>m&&v){
			xx=c;
			v=0;
		}
    }
    if(c==n){
		cout<<xx;
		return 0;
	}
    sort(a+1,a+n+1);
    bool p=1;
    long long ssm=a[1];
    if(ssm>m){
		xo=dc;
		p=0;
	}
    d=a[2]-a[1];
    ssm+=a[2];
    if(ssm>m&&p){
		xo=dc+1;
		p=0;
	}
	dc++;
    for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]==d){
			dc++;
		}
		ssm+=a[i];
		if(ssm>m&&p){
			xo=dc;
			p=0;
		}
	}
	if(p){
		xo=dc;
	}
	if(dc==(n-1)){
		cout<<xo;
		return 0;
	}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long x=a[j]-a[i];
            b[i][j]=x;
        }
    }
    long long x=0;
    for(int i=1;i<=n;i++){
        long long s=0;
        long long c=0;
        for(int j=1;j<=n;j++){
            s+=b[j][i];
            if(b[j][i]){
                c++;
            }
            if(a[i]==a[j]){
                c++;
            }
        }
        if(s<=m){
            x=max(x,c);
        }
    }
    cout<<x;
    return 0;
}
