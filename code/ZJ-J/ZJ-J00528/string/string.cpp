#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long l,r;
	char ch;
}a[200025];
node l[200025],r[200025];
long long ls[200025],rs[200025];
long long p[200025];
int lenl,lenr;
long long sum,ans;
vector<node> L,R;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		char c;
		cin>>p>>c;
		a[i].l=sum+1;
		a[i].r=sum+p;
		a[i].ch=c;
		sum+=p; 
	}int k;
	for(int i=1;i<=n;i++){
		if(a[i].r>sum/2){
			if(a[i].l>sum/2){
				k=i;
				a[i].l=sum/2+1;
				if(sum%2) a[i].l++;
				break;
			}l[i].l=a[i].l,l[i].ch=a[i].ch;
			l[i].r=sum/2;
			a[i].l=sum/2+1;
			ls[i]=l[i].r;
			if(sum%2) a[i].l++;
			k=i;
			lenl++;
			break;
		}else{
			l[i].l=a[i].l,l[i].r=a[i].r;
			l[i].ch=a[i].ch;
			ls[i]=l[i].r;
			lenl++;
		}
	}for(int i=n,j=1;i>=k;i--,j++){
		if(a[i].r<a[i].l) continue;
		r[j].l=(sum-a[i].r+1),r[j].r=(sum-a[i].l+1);
		r[j].ch=a[i].ch;
		rs[j]=r[j].r;
		lenr++;
	}for(int i=1;i<=lenl;i++) p[i]=ls[i];
	for(int i=1;i<=lenr;i++) p[i+lenl]=rs[i];
	sort(p+1,p+lenl+lenr+1);
	for(int i=1;i<=lenl+lenr;i++){
		int ps=lower_bound(ls+1,ls+lenl+1,p[i])-ls;
		L.push_back({p[i-1]+1,p[i],l[ps].ch});
		ps=lower_bound(rs+1,rs+lenr+1,p[i])-rs;
		R.push_back({p[i-1]+1,p[i],r[ps].ch});
	}for(int i=0;i<lenl+lenr;i++){
		if(L[i].ch!=R[i].ch) ans+=L[i].r-L[i].l+1;
	}cout<<ans;
	return 0;
} 
