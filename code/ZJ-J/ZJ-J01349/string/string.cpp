#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=2e5+10;
int n,m,p;
long long sum,bsum,tmp,ttmp,csum,ans,r,rsum,lsum,a[N];
bool flag1;
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	L(i,1,n) {
		cin>>a[i]>>ch[i];
		sum+=a[i];
	}
	bsum=sum/2;
	csum=(sum+1)/2;
	flag1=(bsum%2==1);
	L(i,1,n){
		ttmp=tmp;
		tmp+=a[i];
		if(tmp>=csum){
			R(j,n+1,i+2) a[j]=a[j-1],ch[j]=ch[j-1];
			a[i+1]=tmp-csum;
			ch[i+1]=ch[i];
			a[i]=a[i]-(tmp-bsum);
			p=i;
			break;
		}
	}
	n++;
//	L(i,1,n) cout<<a[i]<<" "<<ch[i]<<"\n";
//	cout<<p;
	r=n+1;
	L(i,1,p){
		lsum+=a[i];
		if(lsum>rsum && ch[r]!=ch[i]) ans+=min((rsum-(lsum-a[i])),a[i]);
		while(rsum<lsum && r>p+1) {
			r--,rsum+=a[r];
			if(rsum<lsum){
				if(ch[r]!=ch[i]) ans+=a[r]; 
			}
		}
		if(ch[r]!=ch[i]) ans+=min((lsum-(rsum-a[r])),a[i]);
	}
	cout<<ans;
	return 0;
}

