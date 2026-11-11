#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;
struct num{
	int sum;
	char w;
}a[N];

num p[N],l[N];
int n,tot,pnum,lnum,plen,llen,ans;

void cut(){
	if(tot%2==0){
		pnum=lnum=tot/2;
	}
	else {
		pnum=lnum=(tot-1)/2;
	}
	for(int i=1,j=1;pnum>0;j++){       
		if(a[i].sum<pnum){
			p[j].sum=a[i].sum;
			p[j].w=a[i].w;
			pnum-=a[i].sum;
			a[i].sum=0;
			i++;
			plen++;
		}
		else {
			if(pnum>0) plen++;
			p[j].sum=pnum;
			p[j].w=a[i].w;
			a[i].sum-=pnum;
			pnum=0;
			break;
		}
	}
	for(int i=n,j=1;lnum>0;j++){       
		if(a[i].sum<lnum){
			l[j].sum=a[i].sum;
			l[j].w=a[i].w;
			lnum-=a[i].sum;
			a[i].sum=0;
			llen++;
			//cout<<"lnum: "<<lnum<<" "<<a[i].sum<<'\n';
			i--;
		}
		else {
			if(lnum>0) llen++;
			l[j].sum=lnum;
			l[j].w=a[i].w;
			a[i].sum-=lnum;
			lnum=0;
			break;
		}
		
	}
}

void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].w;
		tot+=a[i].sum;
	}
	cut();
//	cout<<pnum<<" "<<lnum<<'\n';
//	for(int i=1;i<=10;i++){
//		cout<<l[i].sum<<" "<<l[i].w<<'\n';
//	}
	for(int i=1,j=1;i<=plen&&j<=llen;){
		if(p[i].w==l[j].w){
			if(p[i].sum>l[j].sum){
				p[i].sum-=l[j].sum;
				j++;
			}
			else{
				l[j].sum-=p[i].sum;
				i++;
			}
		}
		else {
			if(p[i].sum>l[j].sum){
				p[i].sum-=l[j].sum;
				ans+=l[j].sum;
				j++;
				
			}
			else{
				l[j].sum-=p[i].sum;
				ans+=p[i].sum;
				i++;
				
			}
		}
	}
	cout<<ans; 
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	Solve();
	return 0;
}
// 3 2 a 2 b 1 c
