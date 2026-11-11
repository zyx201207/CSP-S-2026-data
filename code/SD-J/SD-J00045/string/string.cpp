#include<bits/stdc++.h>
using namespace std;
int n,cntx,cnty,id;
long long tot,oto,ans;
const int N=2e5+5;
struct node{
	int num;
	char c;
}a[N],x[N],y[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		tot+=a[i].num;
	}
	tot/=2;
	oto=tot;
	for(int i=1;i<=n;i++){
		if(a[i].num<tot){
			tot-=a[i].num;
			x[++cntx].num=a[i].num;
			x[cntx].c=a[i].c;
		}
		else {
			x[++cntx].num=tot;
			a[i].num-=tot;
			id=i;
			x[cntx].c=a[i].c;
			break;
		}
	}
	for(int i=n;i>=id;i--){
		if(a[i].num<=0) break;
		if(a[i].num<oto){
			oto-=a[i].num;
			y[++cnty].num=a[i].num;
			y[cnty].c=a[i].c;
		}
		else {
			y[++cnty].num=oto;
			y[cnty].c=a[i].c;
			break;
		}
	}
	int l=1,r=1;
	for(int i=1;i<=cntx+cnty;i++){
		if(l>cntx||r>cnty) break;
		if(x[l].num>y[r].num){
//			cout<<1111<<endl;
			if(x[l].c!=y[r].c) ans+=y[r].num;
			x[l].num-=y[r].num;
			y[r].num=0;
			r++;
			continue;
		}
		else if(x[l].num==y[r].num){
//			cout<<2222<<endl;
			if(x[l].c!=y[r].c) ans+=y[r].num;
			x[l].num=0;
			y[r].num=0;
			l++;
			r++;
			continue;
		}
		else {
//			cout<<3333<<endl;
			if(x[l].c!=y[r].c) ans+=x[l].num;
			y[r].num-=x[l].num;
			x[l].num=0;
			l++;
			continue;
		}
//		cout<<l<<" "<<r<<" "<<x[l].num<<" "<<y[r].num<<endl;
	}
	cout<<ans;
	return 0;
} 
