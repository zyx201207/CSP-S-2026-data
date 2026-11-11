#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],b[N],cntx=1,cnty=1,k,zd=0;
bool cmp(int a,int b){return a>b;}
void sx(){
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		if(m==0) break;
		if(a[i]==a[i-1]){
			cntx++;
		}else{
			ll x=a[i-1]-a[i];
			if(x<=m){
				a[i]=a[i-1];
				m-=x;
				cntx++;
			}else{
				zd=max(zd,cntx);
				cntx=1;
			}
		}
	} 
}
void jx(){
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++){
		if(k==0) break;
		if(b[i]==b[i-1]) cnty++;
		else{
			ll x=b[i]-b[i-1];
			if(x<=k){
				k-=x;
				cnty++;
			}else{
				zd=max(zd,cnty);
				cnty=1;
			} 
		}
	}
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    k=m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=a[i];
	}
	sx();
	jx();
	cout<<zd;
	return 0;
}
