#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct str{
	int num;
	char ch;
}a[N],b[N],cc[N],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	int n,l=0;
	int sum=0,lb=0,lc=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].ch,l+=a[i].num;
	for(int i=1;i<=n;i++) {
		if(sum==l/2) cc[++lc]=a[i];
		else if(sum+a[i].num<=l/2) b[++lb]=a[i],sum+=a[i].num;
		else if(sum+a[i].num>l/2)  cc[++lc].ch=b[++lb].ch=a[i].ch,b[lb].num=l/2-sum,cc[lc].num=a[i].num-l/2+sum,sum=l/2;
	}
	for(int i=lc,j=1;i>=2;i--,j++) c[j]=cc[i];
	if(cc[1].num!=1)               c[lc].ch=cc[1].ch,c[lc].num=cc[1].num-1;
	else lc--;
//	cout<<"\n";
//	for(int i=1;i<=lb;i++) cout<<b[i].ch<<" "<<b[i].num<<"\n"; cout<<"\n";
//	for(int i=1;i<=lc;i++) cout<<c[i].ch<<" "<<c[i].num<<"\n"; cout<<"\n";
	int lenb=0,lenc=0,bi=0,ci=0,ans=0;
	str k; k.num=0,k.ch='a';
	while(bi<=lb){
		lenb+=b[++bi].num;
//		cout<<"lenb="<<lenb<<"\n";
		while(lenc<lenb){
			if(k.num!=0) {
				if(lenc+k.num<=lenb) {
					if(k.ch!=b[bi].ch) ans+=k.num;
					lenc+=k.num;
					k=c[++ci];
				}
				else {
					if(k.ch!=b[bi].ch) ans+=lenb-lenc;
					k.num-=lenb-lenc;
					lenc=lenb;
				}
			}
			else k=c[++ci];
		}
//		cout<<"ans="<<ans<<"\n";
//		cout<<"ci="<<ci<<"\n";
//		cout<<"k="<<k.ch<<" "<<k.num<<"\n\n";
	}
	cout<<ans;
	
	return 0;
}
